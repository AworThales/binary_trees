#include "binary_trees.h"
/**
 * binary_tree_is_full - function that says if a tree is full or not
 * a tree is full if it has tow or none children
 * @tree: tree to check
 * Return: 1 if it is a full 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int right_full = 0, left_full = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left_full && tree->right_full)
		{
			left_full = binary_tree_is_full(tree->left_full);
			right_full = binary_tree_is_full(tree->right_full);
			if (left_full == 0 || right_full == 0)
			{
				return (0);
			}
			return (1);
		}
		else if (!tree->left_full && !tree->right_full)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}
