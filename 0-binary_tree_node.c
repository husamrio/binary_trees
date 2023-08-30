#include "binary_trees.h"

/**
 * binary_tree_node - (Creates) a binary tree node.
 *
 * @value: The new node value to put in.
 *
 * @parent: The parent of the node to create. pointer to.
 *
 * Return: node otherwise NULL if error
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
