#include "binary_trees.h"

/**
 * binary_tree_leaves - Calculates the count of leaf nodes in a binary tree.
 *
 *
 * @tree: A reference (pointer) to the root node of the tree for
 * which the count of leaves needs to be calculated.
 *
 *
 * Return: The number of leaves in the tree.
 *
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
