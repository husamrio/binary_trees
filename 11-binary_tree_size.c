#include "binary_trees.h"

/**
 * binary_tree_size - Determines the size (number of nodes) of a binary tree.
 *
 *
 * @tree: A pointer pointing to the root node of the tree,
 *  for which the size is to be calculated.
 *
 *
 * Return: The count of nodes in the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
