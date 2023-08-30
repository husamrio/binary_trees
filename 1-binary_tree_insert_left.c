#include "binary_trees.h"

/**
 * binary_tree_insert_left - Adds a node to a binary tree as its left child node.
 
 * @value: The value to be stored in the new node.
 
 * @parent: A pointer to the node 
 * to insert the left-child in.
 
 * Return: If  an error occurs or parent is NULL - NULL.
 *         Else - Pointer to  new node.
 */



binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}