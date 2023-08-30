#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Verifies whether a given node
 * is a leaf in a binary tree.
 *
 * @node: A reference (pointer) to the node that needs to be checked.
 *
 * Return: If the node is a leaf, the result will be 1.
 *
 *         Otherwise - 0.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
