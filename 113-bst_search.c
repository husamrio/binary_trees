#include "binary_trees.h"

/**
 * bst_search - Looks for a specific value in a Binary Search Tree (BST).
 *
 *
 * @tree: A reference (pointer) to the root node of the Binary Search Tree
 * (BST) in which the value needs to be searched.
 *
 *
 * @value: The value that needs to be searched for in the Binary Search
 * Tree (BST).
 *
 *
 * Return: If the tree is NULL or the value is not found, the function should
 * return NULL. Otherwise, it should return a pointer to the node
 * containing the value.
 *
 *
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
