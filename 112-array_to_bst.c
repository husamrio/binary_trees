#include "binary_trees.h"

/**
 * array_to_bst - Creates a binary search tree (BST) from an array.
 *
 *
 * @array: A reference (pointer) to the first element of the array
 * that needs to be converted into a binary search tree.
 *
 *
 * @size: The number of elements in the given array.
 *
 *
 * Return: The function should return a pointer to the root
 * node of the created BST if successful, or NULL upon failure.
 *
 *
 *
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
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
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
