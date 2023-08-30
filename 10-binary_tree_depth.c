#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree.
 *
 *
 * @tree: A reference (pointer) to the node for which
 * the depth needs to be measured.
 *
 *
 * Return: 0 if NULL otherwise depth
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ?
			1 + binary_tree_depth(tree->parent) : 0);
}
