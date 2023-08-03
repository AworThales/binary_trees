#include "binary_trees.h"
/**
 * binary_tree_postorder - to print elements of the tree using post-order traversal
 * @tree: tree to go the through
 * @func: function to a use
 * Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
