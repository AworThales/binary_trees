#include "binary_trees.h"

/**
 * binary_tree_is_leaf - to checks if a node is a leaf
 * @node: the pointer to the node to check.
 *
 * Return: 1 if node is a leaf, 0 if node is NULL, and otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node)
	{
		if (!node->right && !node->left)
			return (1);
	}
	return (0);
}
