#include "binary_trees.h"
/**
 * binary_tree_size - a function that return the sizes of a tree
 * @tree: a tree to check
 * Return: the sizes of a tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sizes = 0, right_s = 0, left_s = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left_s = binary_tree_size(tree->left);
		right_s = binary_tree_size(tree->right);
		sizes = right_s + left_s + 1;
	}
	return (sizes);
}
