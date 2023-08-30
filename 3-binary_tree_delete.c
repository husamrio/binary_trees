#include "binary_trees.h"

/**
 * binary_tree_delete - Erases a binary tree.
 *
 * @tree: A reference (pointer) to the root node of the tree to be deleted..
 *
 *
 * Return: Null
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
