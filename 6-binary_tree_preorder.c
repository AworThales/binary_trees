#include "binary_trees.h"
/**
 * binary_tree_preorder - To print elements of a tree using pre-order traversal
 * @tree: tree to go the through
 * @func: function to a use
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
