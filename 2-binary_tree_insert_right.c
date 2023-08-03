#include "binary_trees.h"
/**
 * binary_tree_insert_right - to inserts a node as the right-child of another node
 * if it exists it will move down one level and add a new node first
 * @parent: parent of the specified node
 * @value: the value of a node
 * Return: NULL if its fails or the new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right != NULL)
	{
		a_new_node->right = parent->right;
		parent->right->parent = a_new_node;
	}
	parent->right = a_new_node;
	return (a_new_node);
}
