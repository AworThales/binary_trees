#include "binary_trees.h"
/**
 * binary_tree_height - a Function that measures the my_height of a binary tree
 * @tree: a tree to go through
 * Return: the my_height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t Left_h = 0;
	size_t right_h = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			Left_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((Left_h > right_h) ? Left_h : right_h);
	}
}
/**
 * binary_tree_depth - the depth of specified node from root
 * @tree: a node to be check the depth
 * Return: 0 is it is the root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - a function makes a linked list from depth stage and node
 * @head: a pointer to head of linked list
 * @tree: a node to store
 * @stage: a depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t stage)
{
	link_t *aux, *fresh;

	fresh = malloc(sizeof(link_t));
	if (fresh == NULL)
	{
		return;
	}
	fresh->n = stage;
	fresh->node = tree;
	if (*head == NULL)
	{
		fresh->next = NULL;
		*head = fresh;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		fresh->next = NULL;
		aux->next = fresh;
	}
}
/**
 * recursion - to goes through the complete tree and each stores each node
 * in linked_node function
 * @head: a pointer to head of the linked list
 * @tree: node to check
 * Return: Nothing by default it affects a pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t stage = 0;

	if (tree != NULL)
	{
		stage = binary_tree_depth(tree);
		linked_node(head, tree, stage);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - to print the nodes element in the lever-order
 * @tree: the root node
 * @func: the function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t my_height = 0, begin = 0;
	link_t *aux, *head;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		my_height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (begin <= my_height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (begin == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			begin++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}
