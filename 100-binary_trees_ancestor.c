#include "binary_trees.h"

/**
 * binary_trees_ancestor - Determines the lowest common
 * ancestor of two nodes in a binary tree.
 *
 *
 * @first:A reference (pointer) to the first node for
 * which the lowest common ancestor needs to be found.
 *
 *
 * @second: A reference (pointer) to the second node for
 * which the lowest common ancestor needs to be found.
 *
 *
 * Return: If there are no common ancestors, the function
 * should return NULL. Otherwise, it should return a
 * pointer to the common ancestor node.
 *
 *
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *pop;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, pop));
}
