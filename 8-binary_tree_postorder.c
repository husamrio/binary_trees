#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs traversal of a binary tree by
 *
 * post-order traversal.
 *
 *
 * @tree:A reference (pointer) to the root node of the
 * tree being traversed.
 *
 *
 * @func: A reference (pointer) to the root node
 * of the tree being traversed.
 *
 *
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
