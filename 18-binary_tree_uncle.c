#include "binary_trees.h"

/**
 * binary_tree_uncle - Locates the uncle node (parent's sibling)
 * of a given node in a binary tree.
 *
 *
 * @node: A reference (pointer) to the node for which the
 * uncle needs to be found.
 *
 *
 * Return: If the node is NULL or has no uncle, the
 * function should return NULL.
 * Otherwise, the function should return a pointer
 * to the uncle node.
 *
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
