#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Verifies whether a binary tree is a valid
 * binary search tree (BST) according to its defined rules.
 *
 *
 * @tree: A reference (pointer) to the root node of the binary tree
 * that needs to be checked for being a valid binary search tree.
 *
 *
 * @lo: The value of the smallest node encountered during the traversal.
 *
 *
 * @hi: The value of the largest node encountered during the traversal.
 *
 *
 * Return: If the tree is a valid binary search tree (BST), the
 * function should return 1. Otherwise, it should return 0.
 *
 */

int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}
/**
 * binary_tree_is_bst - Verifies whether a binary tree
 * is a valid binary search tree (BST).
 *
 *
 * @tree: A reference (pointer) to the root node of the binary tree that
 * needs to be checked for being a valid binary search tree.
 *
 *
 * Return: The function should return 1 if the tree is a valid
 * binary search tree (BST), and 0 otherwise.
 *
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
