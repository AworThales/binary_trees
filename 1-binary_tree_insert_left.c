#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * if it exists it will move down one level and add the new node first
 * @parent: the parent of a specified node
 * @value: the value of a node
 * Return: NULL if its fails or a new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *a_new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	a_new_node = binary_tree_node(parent, value);
	if (a_new_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		a_new_node->left = parent->left;
		parent->left->parent = a_new_node;
	}
	parent->left = a_new_node;
	return (a_new_node);
}
