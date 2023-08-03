#include "binary_trees.h"
/**
 * aux_sort - to create the tree using the half element of the array
 * @parent: a parent of the node to create
 * @array: a sorted array
 * @begin: a position where the array starts
 * @last: a position where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	binary_tree_t *aux;
	int midle = 0;
	avl_t *root;

	if (begin <= last)
	{
		midle = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[midle]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, midle - 1);
		root->right = aux_sort(root, array, midle + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - to create a alv tree from sorted array
 * @array: the sorted array
 * @size: the size of the sorted array
 * Return: alv tree form sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
