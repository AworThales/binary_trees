#include "binary_trees.h"
/**
 * successor - to get a next successor that is the min node in a right subtree
 * @node: a tree to check
 * Return: a min value of this tree
 */
int successor(bst_t *node)
{
	int left_successor = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left_successor = successor(node->left_successor);
		if (left_successor == 0)
		{
			return (node->n);
		}
		return (left_successor);
	}

}
/**
 * two_children - a function that gets the next successor using the min
 * value in the right subtree, and then replace the node value for
 * this successor
 * @root: a node tat has two children
 * Return: a the value found
 */
int two_children(bst_t *root)
{
	int my_new_values = 0;

	my_new_values = successor(root->right);
	root->n = my_new_values;
	return (my_new_values);
}
/**
 *remove_type - a function that removes th node depending of its children
 *@root: a node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	if (!root->left_successor && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left_successor = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left_successor && root->right) || (!root->right && root->left_successor))
	{
		if (!root->left_successor)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left_successor = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left_successor;
			else
				root->parent->left_successor = root->left_successor;
			root->left_successor->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - to remove the node from the BST tree
 * @root: a root of a tree
 * @value: a node with this value to remove
 * Return: a tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int a_type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left_successor, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		a_type = remove_type(root);
		if (a_type != 0)
			bst_remove(root->right, a_type);
	}
	else
		return (NULL);
	return (root);
}
