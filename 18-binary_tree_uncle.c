#include "binary_trees.h"

/**
 * binary_tree_uncle - to finds 'uncle' to the node, sibling to `node` parent
 * @node: a node to check
 * Return: a pointer to sibling node of the parent to `node`, or NULL if none found
 * or `node` is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (node->parent && node->parent->parent)
	{
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);
		if (node->parent->parent->right == node->parent)
			return (node->parent->parent->left);
	}
	return (NULL);
}
