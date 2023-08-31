#include "binary_trees.h"

/**
 * is_full_recursive - Recursively checks if a binary tree is
 * full (each node has either 0 or 2 children).
 *
 *
 * @tree: A reference (pointer) to the root node of the
 * binary tree that needs to be checked for being full.
 *
 *
 * Return: If the tree is not full, the function should return 0.
 * If the tree is full, the function should return 1.
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}
/**
 * binary_tree_is_full - Verifies if a binary tree is full
 * (each node has either 0 or 2 children).
 *
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 *
 * Return: If tree is NULL or is not full - 0.
 *         Otherwise - 1.
 *
 *
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
