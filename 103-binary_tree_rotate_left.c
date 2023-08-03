#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a Function that will rotates left of the binary tree.
 * @tree: The root node of a tree
 * Return: a Pointer node of a new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *a_pivot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	a_pivot = tree->right;
	tree->right = a_pivot->left;
	if (a_pivot->left != NULL)
	{
		a_pivot->left->parent = tree;
	}
	a_pivot->left = tree;
	a_pivot->parent = tree->parent;
	tree->parent = a_pivot;
	return (a_pivot);
}
