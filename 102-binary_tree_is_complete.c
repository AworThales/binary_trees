#include "binary_trees.h"
/**
 * new_node - a Function that creates a new_node in the linked_list
 * @node: a Type pointer of node to be created
 * Return: a node created
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *begin;

	begin =  malloc(sizeof(link_t));
	if (begin == NULL)
	{
		return (NULL);
	}
	begin->node = node;
	begin->next = NULL;

	return (begin);
}
/**
 * free_q - Function that free the nodes at the linked list
 * @head: Node of the linked_list
 */
void free_q(link_t *head)
{
	link_t *tmporal_node;

	while (head)
	{
		tmporal_node = head->next;
		free(head);
		head = tmporal_node;
	}
}
/**
 * _push - Function that pushes a node into the stack
 * @node: Type pointer of node of the tree
 * @head: Type head node of in a stack
 * @tails: Type tails node of in a stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tails)
{
	link_t *begin;

	begin = new_node(node);
	if (begin == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tails)->next = begin;
	*tails = begin;
}
/**
 * _pop - a Function that pops the node into the stack
 * @head: Type head node of in a stack
 */
void _pop(link_t **head)
{
	link_t *tmporal_node;

	tmporal_node = (*head)->next;
	free(*head);
	*head = tmporal_node;
}
/**
 * binary_tree_is_complete - a Function that checks if the binary tree is complete
 * @tree: a Type pointer of the node of the tree
 * Return: 1 if is complete 0 if it is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flaged = 0;
	link_t *tails, *head;

	if (tree == NULL)
	{
		return (0);
	}
	head = tails = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flaged == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tails);
		}
		else
			flaged = 1;
		if (head->node->right != NULL)
		{
			if (flaged == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tails);
		}
		else
			flaged = 1;
		_pop(&head);
	}
	return (1);
}
