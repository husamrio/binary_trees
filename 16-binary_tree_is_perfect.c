#include "binary_trees.h"

/**
 * is_leaf - Verifies whether a given node is a leaf in a binary tree.
 *
 *
 * @node: A reference (pointer) to the node that needs to be checked.
 *
 *
 * Return: If the node is a leaf, the function should
 *         return 1; otherwise, it should return 0.
 *
 */

unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Provides the depth of a specified node within a binary tree.
 *
 *
 * @tree: A reference (pointer) to the node for which
 *        the depth needs to be measured..
 *
 *
 * Return: The calculated depth of the node.
 *
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Provides a leaf node from a binary tree.
 *
 *
 * @tree: A reference (pointer) to the root node of the tree
 *        in which you want to find a leaf node.
 *
 *
 * Return: A reference (pointer) to the first encountered
 * leaf node in the tree.
 *
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Recursively determines if a binary tree is perfect
 * (all internal nodes have exactly two children and all leaves are
 *  at the same level).
 *
 *
 * @tree: A reference (pointer) to the root node of the binary
 *  tree that needs to be checked for being perfect.
 *
 *
 * @leaf_depth: The depth of a single leaf node within the binary tree.
 *
 *
 * @level: The level of the current node in the binary tree.
 *
 *
 * Return:If the binary tree is perfect, the function should
 *  return 1. Otherwise, it should return 0.
 *
 */

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Verifies whether a binary tree is perfect
 * (all internal nodes have exactly two children and all leaves are
 * at the same level).
 *
 *
 * @tree: A reference (pointer) to the root node of the binary tree
 * that needs to be checked for being perfect.
 *
 *
 * Return: If the tree is NULL or not perfect, the function should return 0.
 * If the tree is perfect, the function should return 1.
 *
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
