#include "binary_trees.h"
/**
 * tree_is_perfect - a function that says if a tree is perfect or not
 * it has to be the same quantity of the levels in left as right, and also
 * each node has to have 2 nodes or none
 * @tree: a tree to check
 * Return: 0 if is not a perfect or other number that is a level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (tree->left && tree->right)
	{
		left = 1 + tree_is_perfect(tree->left);
		right = 1 + tree_is_perfect(tree->right);
		if (right == left && right != 0 && left != 0)
			return (right);
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
 * @tree: a tree to check
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
