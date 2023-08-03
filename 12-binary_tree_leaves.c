#include "binary_trees.h"
/**
 * binary_tree_leaves - a function that returns a number of leaves in the tree
 * @tree: tree to be check
 * Return: number of a leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t my_leaf = 0, right_l = 0, left_l = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left_l = binary_tree_leaves(tree->left);
		right_l = binary_tree_leaves(tree->right);
		my_leaf = left_l + right_l;
		return ((!left_l && !right_l) ? my_leaf + 1 : my_leaf + 0);
	}
}
