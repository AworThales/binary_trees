#include "binary_trees.h"
/**
 * binary_tree_nodes - a function that returns # of nodes in a tree with children
 * @tree: tree to be check
 * Return: a number of a nodes with children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  my_node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		my_node += ((tree->left || tree->right) ? 1 : 0);
		my_node += binary_tree_nodes(tree->left);
		my_node += binary_tree_nodes(tree->right);
		return (my_node);
	}
}
