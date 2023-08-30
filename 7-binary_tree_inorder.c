#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree.
 *
 *
 * Using in-order traversal technique.
 *
 * @func: A reference (pointer) to a function that will be
 *  called for each node during traversal..
 *
 *
 *
 * @tree: A reference (pointer) to the root node of the
 * tree that needs to be traversed.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
