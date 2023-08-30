#include "binary_trees.h"

/**
 * binary_tree_is_root - Verifies whether a given node is the
 * root of a binary tree.
 *
 *
 * @node: A reference (pointer) to the node that needs to be checked.
 *
 *
 * Return: If the node is a root, the result will be 1.
 *         Else - 0.
 */


int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
