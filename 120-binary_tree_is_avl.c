#include "binary_trees.h"

/**
 * binary_tree_height - a Function that measures the height of a binary tree
 * @tree: a tree to go through
 * Return: a height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			left_h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			right_h = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((left_h > right_h) ? left_h : right_h);
		}
}

/**
 * bal_avl - an Auxiliar function to compare each subtree if its AVL.
 * @tree: a node that point to a tree to check.
 * @high: a node that point to a higher node selected
 * @lower: a node that point to a lower node selected.
 * Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t left_height, right_height, a_balancer;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);
		a_balancer = left_height > right_height ? left_height - right_height : right_height - left_height;
		if (a_balancer > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - To checks if the binary tree is the valid AVL tree.
 * @tree: a node that point to the tree to check.
 * Return: 1 if tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
