#include "binary_trees.h"

/**
 * binary_tree_is_full - to checks if the binary tree is full.
 * @tree: pointer to the root node of a tree to check
 *
 * Return: 0 If tree is NULL, or 1 if its a full binary tree.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
			return (1);
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	}
	return (0);
}
