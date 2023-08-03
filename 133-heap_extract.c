#include "binary_trees.h"

/**
 * enqueue_item_4 - Adds an item to a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tails.
 * @n: A pointer to the queue's size value.
 * @item: The item to add to the queue.
 */
void enqueue_item_4(heap_t **queue_h, heap_t **queue_t,
	int *n, void *item)
{
	heap_t *fresh_node;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		fresh_node = malloc(sizeof(heap_t));
		if (fresh_node == NULL)
			return;
		fresh_node->left = *queue_t;
		fresh_node->right = NULL;
		fresh_node->n = (item != NULL ? ((heap_t *)item)->n : -1);
		fresh_node->parent = (heap_t *)item;
		if (*queue_h == NULL)
			*queue_h = fresh_node;
		if (*queue_t != NULL)
			(*queue_t)->right = fresh_node;
		*queue_t = fresh_node;
		if (n != NULL)
			(*n)++;
	}
}

/**
 * dequeue_item_4 - Removes an item from a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tails.
 * @n: A pointer to the queue's size value.
 *
 * Return: The value of the removed queue.
 */
heap_t *dequeue_item_4(heap_t **queue_h,
	heap_t **queue_t, int *n)
{
	heap_t *tmp2;
	heap_t *tmp3;
	heap_t *node = NULL;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		tmp2 = *queue_h;
		if (tmp2 != NULL)
		{
			node = tmp2->parent;
			if (tmp2->right != NULL)
			{
				tmp3 = tmp2->right;
				tmp3->left = NULL;
				*queue_h = tmp3;
				free(tmp2);
			}
			else
			{
				free(tmp2);
				*queue_h = NULL;
				*queue_t = NULL;
			}
			if (n != NULL)
				(*n)--;
		}
	}
	return (node);
}

/**
 * get_last_heap_node - Gets the last level order node \
 * in a max binary heap tree.
 * @root: The root of the max binary heap tree.
 *
 * Return: A pointer to the last level order node, otherwise NULL.
 */
heap_t *get_last_heap_node(const heap_t *root)
{
	heap_t *final_node = NULL, *present = NULL;
	heap_t *head = NULL, *tails = NULL;
	int n = 0;

	if (root != NULL)
	{
		enqueue_item_4(&head, &tails, &n, (void *)root);
		while (n > 0)
		{
			present = head;
			if (present->parent != NULL)
			{
				final_node = present->parent;
				if (present->parent->left != NULL)
				{
					enqueue_item_4(&head, &tails, &n, (void *)(present->parent->left));
				}
				if (present->parent->right != NULL)
				{
					enqueue_item_4(&head, &tails, &n, (void *)(present->parent->right));
				}
			}
			dequeue_item_4(&head, &tails, &n);
		}
		while (n > 0)
			dequeue_item_4(&head, &tails, &n);
	}
	return (final_node);
}

/**
 * swap_tree_node_with_parent_1 - Swaps a node in a \
 * max binary heap tree with its parent.
 * @node: A pointer to the node's address.
 * @root: A pointer to the root of the tree.
 */
void swap_tree_node_with_parent_1(heap_t **node, heap_t **root)
{
	heap_t *node_copy, *p, *tmp2, *l, *r;

	if ((node != NULL) && ((*node)->parent != NULL) && (root != NULL))
	{
		p = (*node)->parent, node_copy = *node, tmp2 = (*node)->parent->parent;
		l = (*node)->left, r = (*node)->right;
		if ((*node)->parent->left != *node) /* swap from the right */
		{
			if ((tmp2 != NULL) && (tmp2->left == (*node)->parent))
				tmp2->left = *node;
			if ((tmp2 != NULL) && (tmp2->right == (*node)->parent))
				tmp2->right = *node;
			if ((*node)->parent->left != NULL)
				(*node)->parent->left->parent = node_copy;
			(*node)->parent = tmp2, (*node)->left = p->left, (*node)->right = p;
			p->parent = node_copy, p->left = l, p->right = r;
		}
		else /* swap from the left */
		{
			if ((tmp2 != NULL) && (tmp2->left == p))
				tmp2->left = *node;
			if ((tmp2 != NULL) && (tmp2->right == p))
				tmp2->right = *node;
			if ((*node)->parent->right != NULL)
				(*node)->parent->right->parent = *node;
			(*node)->parent = tmp2, (*node)->right = p->right, (*node)->left = p;
			p->parent = node_copy, p->left = l, p->right = r;
		}
		if (l != NULL)
			l->parent = p;
		if (r != NULL)
			r->parent = p;
		if (tmp2 == NULL)
			*root = node_copy;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 *		  The root node will be freed and replaced with
 *		  the last level-order node of the heap.
 *		  Once replaced, the heap will be rebuilt if necessary.
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node or 0 for a failure
 */
int heap_extract(heap_t **root)
{
	int value_right, value = 0, value_2;
	heap_t *node_right, *tmps, *dummy_data, *node, *node_left;

	if ((root != NULL) && (*root != NULL))
	{
		node = *root;
		node_left = node->left;
		node_right = node->right;
		value = node->n;
		tmps = get_last_heap_node(node);
		*root = ((tmps != NULL) && (tmps->parent != NULL) ? tmps : NULL);
		if ((tmps != NULL) && (tmps->parent != NULL))
		{
			if (tmps->parent->left == tmps)
				tmps->parent->left = NULL;
			if (tmps->parent->right == tmps)
				tmps->parent->right = NULL;
			tmps->parent = NULL;
			tmps->left = (node_left != tmps ? node_left : NULL);
			tmps->right = (node_right != tmps ? node_right : NULL);
			if ((node_left != NULL) && (node_left != tmps))
				node_left->parent = tmps;
			if ((node_right != NULL) && (node_right != tmps))
				node_right->parent = tmps;
			while (tmps != NULL)
			{
				value_2 = tmps->left != NULL ? tmps->left->n : tmps->n;
				value_right = tmps->right != NULL ? tmps->right->n : tmps->n;
				dummy_data = value_2 > value_right ? tmps->left : tmps->right;
				if ((dummy_data != NULL) && (dummy_data->n > dummy_data->parent->n))
					swap_tree_node_with_parent_1(&dummy_data, root);
				else
					break;
			}
		}
		free(node);
	}
	return (value);
}
