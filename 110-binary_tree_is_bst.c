#include "binary_trees.h"
/**
 * check_sub_tree_Left - to check if all nodes are smaller than
 * the root specified
 * @node: a node in a tree to be verify condition
 * @max: a value to be compare
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int right_check = 0, left_check = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left_check = check_sub_tree_Left(node->left_check, max);
		right_check = check_sub_tree_Left(node->right_check, max);
		if (left_check == right_check && left_check == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - to check if all the nodes are bigger than the
 * root specified
 * @node: a node in a tree to verify condition
 * @min: a value to be compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int right_check = 0, left_check = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left_check = check_sub_tree_Right(node->left_check, min);
		right_check = check_sub_tree_Right(node->right_check, min);
		if (left_check == right_check && left_check == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - to says if a tree is the bst or not
 * the process here is first verify that a left_check node be smaller than the root
 * then verify if the right_check node is bigger than th root.
 * after that verify if the left_check subtree has nodes smaller than root
 * and the right_check subtree has bigger nodes than root
 * @tree: a node that point to a tree to check
 * Return: 1 if it is a BST or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int right_check = 2, my_value = 0, left_check = 2;

	if (tree == NULL)
		return (0);
	if (tree->left_check && tree->left_check->n > tree->n)
		return (0);
	if (tree->right_check && tree->right_check->n < tree->n)
		return (0);
	if (tree->left_check && tree->left_check->n < tree->n)
	{
		my_value = check_sub_tree_Left(tree->left_check, tree->n);
		if (my_value == 0)
			return (0);
		left_check = binary_tree_is_bst(tree->left_check);
	}
	if (tree->right_check && tree->right_check->n > tree->n)
	{
		my_value = check_sub_tree_Right(tree->right_check, tree->n);
		if (my_value == 0)
			return (0);
		right_check = binary_tree_is_bst(tree->right_check);
	}
	if (left_check != 2 || right_check != 2)
	{
		if (left_check == 0 || right_check == 0)
			return (0);
	}
	return (1);
}
