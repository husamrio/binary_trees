#include "binary_trees.h"

/**
 * array_to_avl - Creates an AVL tree from an array, ensuring
 *  the AVL property is maintained.
 *
 *
 * @array: A reference (pointer) to the first element of the
 * array that needs to be converted into an AVL tree.
 *
 *
 * @size: The number of elements in the given array.
 *
 *
 * Return: The function should return a pointer to the root node
 * of the created AVL tree if successful, or NULL upon failure.
 *
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
