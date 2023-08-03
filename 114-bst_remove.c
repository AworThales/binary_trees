#include "binary_trees.h"

/**
 * find_node - to Finds a node with a given value in a binary search tree.
 * @root: root of the binary search tree.
 * @value: value of the node.
 *
 * Return: pointer to the found node, otherwise NULL.
 */
bst_t *find_node(bst_t *root, int value)
{
	bst_t *node = NULL;

	if (root != NULL)
	{
		if (root->left != NULL)
			node = root->left->parent;
		if ((node == NULL) && (root->right != NULL))
			node = root->right->parent;
		while (node != NULL)
		{
			if (node->n < value)
				node = node->right;
			else if (node->n > value)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * replace_with_successor - to Replaces a node with its inorder \
 * successor in a binary search tree.
 * @node: pointer to the node in the binary search tree.
 *
 * Return: pointer to the node's inorder successor node.
 */
bst_t *replace_with_successor(bst_t **node)
{
	bst_t *fresh_node;

	fresh_node = (*node)->right;
	while ((fresh_node != NULL) && (fresh_node->left != NULL))
		fresh_node = fresh_node->left;
	if ((fresh_node != NULL) && (fresh_node == (*node)->right))
	{
		fresh_node->parent = (*node)->parent;
		fresh_node->left = (*node)->left;
		if ((*node)->left != NULL)
			(*node)->left->parent = fresh_node;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = fresh_node;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = fresh_node;
		}
	}
	else if (fresh_node != NULL)
	{
		fresh_node->parent->left = fresh_node->right;
		if (fresh_node->right != NULL)
			fresh_node->right->parent = fresh_node->parent;
		fresh_node->parent = (*node)->parent;
		fresh_node->left = (*node)->left;
		fresh_node->right = (*node)->right;
		(*node)->left->parent = fresh_node;
		(*node)->right->parent = fresh_node;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = fresh_node;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = fresh_node;
		}
	}
	return (fresh_node);
}

/**
 * bst_remove - Removes a node with a given value in a binary search tree.
 *		If the node to be deleted has two children, it will be replaced
 *		with its first in-order successor (not predecessor)
 * @root: a pointer to the root node of the tree where you will remove a node.
 * @value: the value to remove in the tree.
 *
 * Return: a pointer to the new root node of the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *fresh_root = root, *fresh_node = NULL;

	if (fresh_root != NULL)
	{
		node = find_node(root, value);
		if ((node != NULL) && (node->n == value))
		{
			if ((node->left == NULL) && (node->right == NULL))
			{
				if (node->parent != NULL)
				{
					if (node->parent->left == node)
						node->parent->left = NULL;
					if (node->parent->right == node)
						node->parent->right = NULL;
				}
			}
			else if ((node->left != NULL) ^ (node->right != NULL))
			{
				fresh_node = (node->left != NULL ? node->left : node->right);
				if (node->parent != NULL)
				{
					if (node->parent->left == node)
						node->parent->left = fresh_node;
					else if (node->parent->right == node)
						node->parent->right = fresh_node;
				}
				fresh_node->parent = node->parent;
			}
			else
			{
				fresh_node = replace_with_successor(&node);
			}
			fresh_root = (node->parent == NULL ? fresh_node : root);
			free(node);
		}
	}
	return (fresh_root);
}
