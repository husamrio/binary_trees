#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Calculates the height of a binary tree.
 *
 *
 * @tree: A reference (pointer) to the root node of the tree
 * for which the height needs to be measured.
 *
 *
 * Return: If the tree is NULL, your function should return 0.
 * Otherwise, it should return the calculated height of the tree.
 *
 *
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - Verifies whether a binary tree is a valid AVL tree,
 * meaning it satisfies the AVL tree balancing property.
 *
 *
 * @tree: A reference (pointer) to the root node of the binary tree
 * that needs to be checked for being a valid AVL tree.
 *
 *
 * @lo: The value of the smallest node encountered during the traversal.
 *
 *
 * @hi: The value of the largest node encountered during the traversal.
 *
 *
 * Return: If the tree is a valid AVL tree, the function should return 1.
 *
 * Otherwise, it should return 0.
 *
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Verifies whether a binary tree is a valid AVL tree,
 * ensuring that it satisfies the AVL tree balancing property.
 *
 *
 * @tree: A reference (pointer) to the root node of the binary tree that
 * needs to be checked for being a valid AVL tree.
 *
 *
 * Return: The function should return 1 if the tree is a valid
 * AVL tree, and 0 otherwise.
 *
 *
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
