#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - counts the number of nodes in a binary tree
 * @root: pointer to the root node
 *
 * Return: number of nodes in the tree
 */
static size_t tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + tree_size(root->left) + tree_size(root->right));
}

/**
 * get_last_node - gets the last node in level-order
 * @root: pointer to the root node
 * @index: level-order index of the target node
 *
 * Return: pointer to the target node, or NULL on failure
 */
static heap_t *get_last_node(heap_t *root, size_t index)
{
	size_t mask;

	if (root == NULL)
		return (NULL);

	mask = 1;
	while (mask <= index)
		mask <<= 1;

	mask >>= 2;

	while (mask > 0)
	{
		if (index & mask)
			root = root->right;
		else
			root = root->left;

		mask >>= 1;
	}

	return (root);
}

/**
 * heapify_down - restores the max heap property from a node downward
 * @root: pointer to the node to heapify
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest;
	int tmp;

	while (root != NULL)
	{
		largest = root;

		if (root->left != NULL && root->left->n > largest->n)
			largest = root->left;

		if (root->right != NULL && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;

		root = largest;
	}
}

/**
 * heap_extract - extracts the root value of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *last;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	size = tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root, size);

	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	heapify_down(*root);

	return (value);
}
