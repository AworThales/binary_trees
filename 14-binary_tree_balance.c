#include "binary_trees.h"

/**
 * binary_tree_height - yo measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree or 0 If tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_h = 0, right_h = 0;

		left_h = tree->left ? (1 + binary_tree_height(tree->left)) : 0;
		right_h = tree->right ? (1 + binary_tree_height(tree->right)) : 0;

		return (left_h > right_h ? left_h : right_h);
	}
	return (0);
}

/**
 * binary_tree_balance - to measures the balance factor of a binary tree.
 *		Balance = Height of left subtree – Height of right subtree.
 *
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: 0 if tree is NULL or the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		int right_h = 0, left_h = 0;

		right_h = tree->right ? (int)binary_tree_height(tree->right) : -1;
		left_h = tree->left ? (int)binary_tree_height(tree->left) : -1;

		return (left_h - (right_h));

	}
	return (0);
}
