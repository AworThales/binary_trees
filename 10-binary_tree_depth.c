#include "binary_trees.h"

/**
 * binary_tree_depth - to measures the depths of a node in a binary tree.
 * @tree: the pointer to the node to measure the depths
 * Return: a depths or 0 If tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t depths = 0;

		depths = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;

		return (depths);
	}
	return (0);
}
