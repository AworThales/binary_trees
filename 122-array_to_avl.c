#include "binary_trees.h"

/**
 * array_to_avl - to turns an array to th avl tree
 * @array: an array to turns to the AVL tree
 * @size: the size of the array
 * Return: a AVL tree from array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t t, s = 0;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (t = 0; t < size; t++)
	{
		for (s = 0; s < t; s++)
		{
			if (array[s] == array[t])
				break;
		}
		if (s == t)
		{
			if (avl_insert(&root, array[t]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
