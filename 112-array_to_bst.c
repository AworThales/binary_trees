#include "binary_trees.h"
/**
 * array_to_bst - turns an array to a BST tree
 * @array: array to turns to BST tree
 * @size: size of array
 * Return: BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *roots;
	size_t t = 0;

	roots = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; t < size; t++)
	{
		if (t == 0)
		{
			bst_insert(&roots, array[t]);
		}
		else
		{
			bst_insert(&roots, array[t]);
		}
	}
	return (roots);
}
