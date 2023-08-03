#include "binary_trees.h"

/**
 * array_to_heap - to builds the Max Binary Heap tree from an array.
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array.
 *
 * Return: a pointer to a root node of a created Binary Heap,
 *	   or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t t;

	if (array != NULL)
	{
		for (t = 0; t < size; t++)
		{
			heap_insert(&root, *(array + t));
		}
	}
	return (root);
}
