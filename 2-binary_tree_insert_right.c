#include "binary_trees.h"

/**
 * binary_tree_insert_right - Add a node as the right child
 * of another node in a binary tree.
 *
 * @value: The data to be stored in the new node..
 *
 * @parent: A reference (pointer) to the node where the right
 * child is to be inserted.
 *
 * Return: If the parent is NULL or an error occurs, the result will be NULL.
 *         Else - a pointer to the new node.
 */


binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
