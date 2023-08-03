#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary node tree
 * @parent: pointer to the parent node of the node that is created
 * @value: Value of the node to be insert in the new node
 * Return: the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *a_new_node;

	a_new_node = malloc(sizeof(binary_tree_t));
	if (a_new_node == NULL)
	{
		return (NULL);
	}
	a_new_node->n = value;
	a_new_node->parent = parent;
	a_new_node->left = NULL;
	a_new_node->right = NULL;
	return (a_new_node);
}
