#include "binary_trees.h"

/**
 * _realloc - to Re-allocates the memory block
 * @ptr: A pointer to a previous memory block
 * @old_size: size of a old memory block
 * @new_size: asize of a new memory block
 *
 * Return: pointer to the new memory block otherwise NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int min_size = old_size < new_size ? old_size : new_size;
	unsigned int t;
	void *fresh_ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL)
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
		fresh_ptr = malloc(new_size);
		if (fresh_ptr != NULL)
		{
			for (t = 0; t < min_size; t++)
				*((char *)fresh_ptr + t) = *((char *)ptr + t);
			free(ptr);
			return (fresh_ptr);
		}
		free(ptr);
		return (NULL);
	}
	else
	{
		fresh_ptr = malloc(new_size);
		return (fresh_ptr);
	}
}

/**
 * heap_to_sorted_array - to converts the Binary Max Heap to a sorted
 *			  array of integers.
 *			  Since we are using Max Heap, the returned array will be
 *			  sorted in descending order
 * @heap: pointer to a root node of a heap to convert
 * @size: address to store a size of a array
 *
 * Return: A pointer to the array, otherwise NULL.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	heap_t *root;
	int *array = NULL;
	size_t s = 0;
	int my_values;

	if (heap != NULL)
	{
		root = heap;
		while (root != NULL)
		{
			my_values = heap_extract(&root);
			array = _realloc(array, sizeof(int) * s, sizeof(int) * (s + 1));
			*(array + s) = my_values;
			s++;
		}
	}
	if (size != NULL)
		*size = s;
	return (array);
}
