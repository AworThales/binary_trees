#include "binary_trees.h"

/**
 * binary_tree_height - a Function that measures the height of a binary tree
 * @tree: a tree to go through
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_h = 0;
	size_t left_h = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			left_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((left_h > right_h) ? left_h : right_h);
		}
}

/**
 * binary_tree_balance - a Measures balance factor of a binary tree
 * @tree: a tree to go through
 * Return: a balanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, tot = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		tot = left - right;
	}
	return (tot);
}

/**
 * tree_is_perfect - function that says if a tree is perfect or not
 * it has to be the same quantity of levels in left as right, and also
 * each node has to have 2 nodes or none
 * @tree: tree to check
 * Return: 0 if is not a perfect or other number that is the level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree->left && tree->right)
	{
		left_h = 1 + tree_is_perfect(tree->left);
		right_h = 1 + tree_is_perfect(tree->right);
		if (right_h == left_h && right_h != 0 && left_h != 0)
			return (right_h);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - the perfect or not a tree
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int answer = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		answer = tree_is_perfect(tree);
		if (answer != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - to checks if a binary tree is a valid Max Binary Heap
 * @tree: a tree to check
 * Return: 1 is it is or 0 if not
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int my_values;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	my_values = binary_tree_balance(tree);
	if (my_values == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (my_values == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
