#include "binary_trees.h"
/**
 * bst_insert - to insert nodes in the order to create the BST tree
 * @tree: a tree to be create with type BST
 * @value: a value of the node to be insert
 * Return: BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *aux;
	bst_t *my_temp, *fresh;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		fresh = (bst_t *)aux;
		*tree = fresh;
	}
	else
	{
		my_temp = *tree;
		if (value < my_temp->n)
		{
			if (my_temp->left)
				fresh = bst_insert(&my_temp->left, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)my_temp, value);
				fresh = my_temp->left = (bst_t *)aux;
			}
		}
		else if (value > my_temp->n)
		{
			if (my_temp->right)
				fresh = bst_insert(&my_temp->right, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)my_temp, value);
				fresh = my_temp->right = aux;
			}
		}
		else
			return (NULL);
	}
	return (fresh);
}
