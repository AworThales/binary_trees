#include "binary_trees.h"

/**
 * binary_tree_is_root - to checks if the given node is the root
 * @node: the pointer to the node to check
 *
 * Return: 1 if node is the root, 0 if node is null or otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node)
	{
		if (!node->parent)
			return (1);
	}
	return (0);
}
