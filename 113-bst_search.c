#include "binary_trees.h"
/**
 * bst_search - a search for the special value in a tree and return the node
 * @tree: tree to go through
 * @value: a value to be search
 * Return: a node with the value or NULL if a value is not in the tree
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *seen;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		seen = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		seen = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (seen);
}
