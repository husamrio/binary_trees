#include "binary_trees.h"

/**
 * bst_insert - Adds a value to a Binary Search Tree (BST).
 *
 *
 * @tree: A reference to a pointer that points to the root node
 *  of the Binary Search Tree (BST) where the value needs to be inserted.
 *
 *
 * @value: The data value that should be stored in the node to be inserted.
 *
 *
 * Return: The function should return a pointer to the newly created
 * node if successful, or NULL on failure.
 *
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < curr->n) /* Inserts the value in the left */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->left = new);
		}
		if (value > curr->n) /* Inserts the value in the right subtree of */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = new);
		}
	}
	return (NULL);
}
