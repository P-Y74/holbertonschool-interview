#include "binary_trees.h"
#include <stdio.h>
#include <limits.h>

/**
 * tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * is_avl - recursively checks if a tree is a valid AVL tree
 * @tree: pointer to the root node
 * @min: minimum allowed value
 * @max: maximum allowed value
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0
 */
int is_avl(const binary_tree_t *tree, long min, long max)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height - right_height > 1 ||
		right_height - left_height > 1)
		return (0);

	if (!is_avl(tree->left, min, tree->n))
		return (0);

	if (!is_avl(tree->right, tree->n, max))
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree, LONG_MIN, LONG_MAX));
}
