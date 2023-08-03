#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a Function thatwill rotates right a binary tree.
 * @tree: The root node of a tree
 * Return: a Pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *a_pivot;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	a_pivot = tree->left;
	tree->left = a_pivot->right;
	if (a_pivot->right != NULL)
	{
		a_pivot->right->parent = tree;
	}
	a_pivot->right = tree;
	a_pivot->parent = tree->parent;
	tree->parent = a_pivot;
	return (a_pivot);
}
