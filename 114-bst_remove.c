#include "binary_trees.h"

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Provides the minimum value stored in a Binary
 * Search Tree (BST).
 *
 *
 * @root: A reference (pointer) to the root node of the Binary
 * Search Tree (BST)
 * that needs to be searched for the minimum value.
 *
 *
 * Return: The minimum value present in the given Binary Search Tree (BST).
 *
 *
 */

bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Removes a node from a Binary Search Tree (BST).
 *
 *
 * @root: A reference (pointer) to the root node of the Binary
 * Search Tree (BST) from which a node needs to be deleted.
 *
 *
 * @node: A reference (pointer) to the node that needs to be
 *  deleted from the Binary Search Tree (BST).
 *
 *
 * Return: A reference (pointer) to the new root node of the
 * Binary Search Tree (BST) after the deletion.
 *
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;


	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Deletes a node from a binary search tree
 * using a recursive approach.
 *
 *
 * @root: A reference (pointer) to the root node of the Binary Search Tree
 * (BST) from which a node needs to be removed.
 *
 *
 * @node: A pointer to the current node in the BST.
 *
 *
 * @value: The value to remove from the BST.
 *
 *
 * Return: A pointer to the root node after deletion.
 *
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Deletes a node from a binary search tree.
 *
 *
 * @root: A reference (pointer) to the root node of the Binary
 *  Search Tree (BST) from which a node needs to be removed.
 *
 *
 * @value: The value that needs to be removed from the
 * Binary Search Tree (BST).
 *
 *
 * Return: A reference (pointer) to the new root node of the
 * Binary Search Tree (BST) after the specified value has been removed.
 *
 *
 * Description In the case where the node to be deleted has two children,
 * it will be replaced with its first in-order successor.
 *
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
