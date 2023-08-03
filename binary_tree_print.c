#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - a Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: an Offset to print
 * @depth: a Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int right, check_left, t, a_width, left;

	if (!tree)
		return (0);
	check_left = (tree->parent && tree->parent->left == tree);
	a_width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + a_width, depth + 1, s);
	for (t = 0; t < a_width; t++)
		s[depth][offset + left + t] = b[t];
	if (depth && check_left)
	{
		for (t = 0; t < a_width + right; t++)
			s[depth - 1][offset + left + a_width / 2 + t] = '-';
		s[depth - 1][offset + left + a_width / 2] = '.';
	}
	else if (depth && !check_left)
	{
		for (t = 0; t < left + a_width; t++)
			s[depth - 1][offset - a_width / 2 + t] = '-';
		s[depth - 1][offset + left + a_width / 2] = '.';
	}
	return (left + a_width + right);
}

/**
 * _height - to Measures the a_height of a binary tree
 *
 * @tree: a Pointer to the node to measures the a_height
 *
 * Return: a_height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t left_h;
	size_t right_h;

	left_h = tree->left ? 1 + _height(tree->left) : 0;
	right_h = tree->right ? 1 + _height(tree->right) : 0;
	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_print - To Prints the binary tree
 *
 * @tree: The Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	size_t t, n, a_height;
	char **s;

	if (!tree)
		return;
	a_height = _height(tree);
	s = malloc(sizeof(*s) * (a_height + 1));
	if (!s)
		return;
	for (t = 0; t < a_height + 1; t++)
	{
		s[t] = malloc(sizeof(**s) * 255);
		if (!s[t])
			return;
		memset(s[t], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (t = 0; t < a_height + 1; t++)
	{
		for (n = 254; n > 1; --n)
		{
			if (s[t][n] != ' ')
				break;
			s[t][n] = '\0';
		}
		printf("%s\n", s[t]);
		free(s[t]);
	}
	free(s);
}
