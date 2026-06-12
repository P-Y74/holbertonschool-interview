#include "binary_trees.h"
#include <stdio.h>

/**
 * create_node - creates a new AVL tree node
 * @value: value to store in the node
 * @parent: pointer to the parent node
 *
 * Return: pointer to the new node, or NULL on failure
 */
static avl_t *create_node(int value, avl_t *parent)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * build_avl - recursively builds an AVL tree from a sorted array
 * @array: sorted array of integers
 * @start: starting index
 * @end: ending index
 * @parent: parent node
 *
 * Return: pointer to the root of the subtree, or NULL on failure
 */
static avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	node = create_node(array[mid], parent);
	if (node == NULL)
		return (NULL);

	node->left = build_avl(array, start, mid - 1, node);
	node->right = build_avl(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root node, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, size - 1, NULL));
}
