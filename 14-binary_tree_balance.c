#include "binary_trees.h"

/**
 * binary_tree_balance -Calculates the balance factor of a binary tree..
 *
 *
 * @tree:A reference (pointer) to the root node of the tree
 * for which the balance factor needs to be measured.
 *
 *
 * Return: If the tree is NULL, return 0; otherwise,
 *  return the calculated balance factor..
 *
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) -
				binary_tree_height(tree->right));
	}

	return (0);
}

/**
 * binary_tree_height - Calculates the height of a binary tree.
 *
 *
 * @tree: A reference (pointer) to the root node of the tree
 * for which the height needs to be measured.
 *
 *
 * Return: If the tree is NULL, your function should return 0;
 * otherwise, return the calculated height..
 *
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
