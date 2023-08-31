#include "binary_trees.h"

/**
 * binary_tree_sibling - Locates the sibling node of a
 *  given node in a binary tree.
 *
 *
 * @node: A reference (pointer) to the node for which
 *  the sibling needs to be found.
 *
 *
 * Return: If the node is NULL or there is no sibling,
 * the function should return NULL. Otherwise, it
 * should return a pointer to the sibling node.
 *
 *
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
