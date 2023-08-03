#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that checks an ancestor
 * @first: a First node
 * @second: a Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *right_searc, *left_searc;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	right_searc = first->parent;
	left_searc = second->parent;
	if (right_searc == NULL || first == left_searc || (!right_searc->parent && left_searc))
	{
		return (binary_trees_ancestor(first, left_searc));
	}
	else if (left_searc == NULL || right_searc == second || (!left_searc->parent && right_searc))
	{
		return (binary_trees_ancestor(right_searc, second));
	}
	return (binary_trees_ancestor(right_searc, left_searc));
}
