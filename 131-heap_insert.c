#include "binary_trees.h"

/**
 * max_size_t - finds larger of two size_t values
 * @a: first value to compare
 * @b: second value to compare
 * Return: larger size_t value, or value of both if equal
 */
size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: root node from which to measure, starting at 0
 * Return: levels from root, or 0 if `tree` is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + max_size_t(binary_tree_height(tree->left),
			       binary_tree_height(tree->right)));
}

/**
 * binary_tree_nodes - counts the total nodes in a binary tree
 * @tree: root node from which to measure
 * Return: total non-leaf nodes at or below `tree`, or 0 if `tree` is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}

/**
  * binary_tree_is_perfect - checks if a binary tree is perfect, meaning all
  * nodes except for leaves have two children, and all leaves at same level
  * @tree: root node below which to check
  * Return: 1 if `tree` and all nodes below it each have 2 children, 0 if not
  * or if `tree` is NULL
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, i, pow2 = 1;
	size_t total_nodes;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	total_nodes = binary_tree_nodes(tree);

	for (i = 0; i < height; i++)
		pow2 *= 2;

	return (pow2 - 1 == (int)total_nodes);
}

/**
 * binary_tree_complete_insert - recursively proceeds through a `heap_t`
 * binary tree to add a fresh leaf in level order, while keeping tree complete
 * @tree: root node of tree to traverse
 * @value: value to store in the fresh node
 * Return: pointer to the fresh node, or NULL on failure
 */
heap_t *binary_tree_complete_insert(heap_t *tree, int value)
{
	heap_t *fresh = NULL;

	if (tree->left && tree->right)
	{
		if (!binary_tree_is_perfect(tree) &&
		    binary_tree_is_perfect(tree->left))
			fresh = binary_tree_complete_insert(tree->right, value);
		else
			fresh = binary_tree_complete_insert(tree->left, value);
	}
	else
	{
		fresh = binary_tree_node(tree, value);
		if (!fresh)
			return (NULL);

		if (!(tree->left))
			tree->left = fresh;
		else
			tree->right = fresh;
	}

	return (fresh);
}


/**
 * heap_insert - to inserts the value into a max binary heap
 * @root: a double pointer to a root node of the Heap
 * @value: a value to store in the node to be inserted
 * Return: a pointer to a inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int a_swap;
	heap_t *tmp = NULL, *fresh = NULL;

	/* no root, start fresh tree */
	if (!(*root))
	{
		fresh = binary_tree_node(NULL, value);
		if (!fresh)
			return (NULL);
		*root = fresh;
		return (fresh);
	}

	/* to find next available leaf position in level order */
	fresh = binary_tree_complete_insert(*root, value);
	if (!fresh)
		return (NULL);

	/* to sort fresh value into position in heap by value of fresh->n */
	tmp = fresh;
	while (tmp && tmp->parent && tmp->n > tmp->parent->n)
	{
		a_swap = tmp->n;
		tmp->n = tmp->parent->n;
		tmp->parent->n = a_swap;
		tmp = tmp->parent;
	}

	return (tmp);
}
