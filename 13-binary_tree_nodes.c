#include "binary_trees.h"

/**
 * binary_tree_nodes - Calculates the count of nodes in a binary
 *  tree that have at least one child.
 *
 *
 *
 * @tree: A reference (pointer) to the root node of the tree for which
 * the count of nodes with at least one child needs to be calculated.
 *
 *
 * Return: If the tree is NULL, the function should return 0;
 * otherwise, return the count of nodes meeting the criteria.
 *
 *
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
