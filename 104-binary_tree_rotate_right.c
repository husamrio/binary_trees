#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 *
 *
 * @tree: A reference (pointer) to the root node of the binary
 *  tree that needs to be right-rotated.
 *
 *
 * Return: A reference (pointer) to the new root node of the
 * binary tree after the right rotation.
 *
 *
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	tmp = pivot->right;
	pivot->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	return (pivot);
}
