#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree.
 *
 *
 * Using pre-order traversal technique.
 *
 * @func: A reference (pointer) to a function that will be
 * called for each node..
 *
 *
 * @tree: Reference (pointer) to the root node of the tree
 *  that needs to be traversed.
 *
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
