#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree.
 *
 *
 * @tree:A reference (pointer) to the root node of the
 * tree for which the height needs to be measured.
 *
 *
 * Return: If the tree is NULL, your function should return 0;
 *
 * otherwise, return the calculated height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}
