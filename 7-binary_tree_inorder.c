#include "binary_trees.h"

/**
 * binary_tree_inorder - a recursively proceeds through the `binary_tree_t`
 * binary tree using in-order traversal
 * @tree: the root node of tree to traverse
 * @func: a pointer to function to call for each node; value in the node is
 * passed as the parameter to `func`
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
