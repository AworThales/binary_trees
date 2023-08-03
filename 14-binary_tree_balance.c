#include "binary_trees.h"

/**
 * binary_tree_height_b - a measures height of the binary tree for the bal tree
 * @tree: to tree to go through
 * Return: the height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t right_h = 0;
	size_t left_h = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			left_h = tree->left_h ? 1 + binary_tree_height_b(tree->left_h) : 1;
			right_h = tree->right_h ? 1 + binary_tree_height_b(tree->right_h) : 1;
		}
		return ((left_h > right_h) ? left_h : right_h);
	}
}

/**
 * binary_tree_balance - to measures balance factor of the binary tree
 * @tree: tree to go the through
 * Return: a balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h = 0, tot = 0, right_h = 0;

	if (tree)
	{
		left_h = ((int)binary_tree_height_b(tree->left_h));
		right_h = ((int)binary_tree_height_b(tree->right_h));
		tot = left_h - right_h;
	}
	return (tot);
}
