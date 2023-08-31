#include "binary_trees.h"

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
int balance(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
size_t height(const binary_tree_t *tree);

/**
 * height - Calculates the height of a binary tree.
 *
 *
 * @tree:A reference (pointer) to the root node of the tree
 * for which the height needs to be measured.
 *
 *
 * Return: If the tree is NULL, your function should return 0.
 * Otherwise, it should return the calculated height of the tree.
 *
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Calculates the balance factor of a binary tree.
 *
 *
 * @tree: A reference (pointer) to the root node of the tree for
 * which the balance factor needs to be measured.
 *
 *
 * Return: If the tree is NULL, the function should return 0.
 * Otherwise, it should return the calculated balance factor.
 *
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Recursively inserts a value into an AVL tree,
 * ensuring the tree's balance property is maintained.
 *
 *
 * @tree: A reference to a pointer that points to the root node of the
 * AVL tree where the value needs to be inserted.
 *
 *
 * @parent: The parent node of the current node being considered
 * during the insertion process.
 *
 *
 * @new: A reference to a pointer that will store the newly created
 * node during the insertion process.
 *
 *
 * @value: The value that needs to be inserted into the AVL tree.
 *
 *
 * Return: The function should return a pointer to the new root node
 * of the AVL tree after insertion if successful, or NULL on failure.
 *
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Adds a value into an AVL tree, maintaining
 * the AVL tree property.
 *
 *
 * @tree: A reference to a pointer that points to the root node of the AVL tree
 * where the value needs to be inserted.
 *
 *
 * @value: The value that needs to be inserted into the AVL tree.
 *
 *
 * Return: The function should return a pointer to the inserted
 * node if successful, or NULL on failure.
 *
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
