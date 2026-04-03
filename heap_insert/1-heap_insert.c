#include <stdlib.h>
#include "binary_trees.h"

/**
 * enqueue - Adds a heap node to the end of a queue
 *
 * @front: Double pointer to the front of the queue
 * @rear: Double pointer to the rear of the queue
 * @node: Pointer to the heap node to enqueue
 *
 * Return: 1 on success, 0 on failure
 */
static int enqueue(queue_t **front, queue_t **rear, heap_t *node)
{
	queue_t *new_queue = malloc(sizeof(queue_t));

	if (new_queue == NULL)
		return (0);

	new_queue->node = node;
	new_queue->next = NULL;

	if (*front == NULL)
	{
		*front = new_queue;
		*rear = new_queue;
	}
	else
	{
		(*rear)->next = new_queue;
		*rear = new_queue;
	}
	return (1);
}

/**
 * dequeue - Removes and returns the first heap node from a queue
 *
 * @front: Double pointer to the front of the queue
 * @rear: Double pointer to the rear of the queue
 *
 * Return: Pointer to the dequeued heap node, or NULL if the queue is empty
 */
static heap_t *dequeue(queue_t **front, queue_t **rear)
{
	queue_t *temp;
	heap_t *node;

	if (*front == NULL)
		return (NULL);

	temp = *front;
	node = temp->node;
	*front = temp->next;

	if (*front == NULL)
		*rear = NULL;
	free(temp);
	return (node);
}

/**
 * find_parent - Finds the first heap node with an available child position
 *
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the parent node where a new node can be inserted,
 *         or NULL on failure
 */
static heap_t *find_parent(heap_t *root)
{
	queue_t *front, *rear;
	heap_t *current;

	front = NULL;
	rear = NULL;
	if (enqueue(&front, &rear, root) == 0)
		return (NULL);
	while (front != NULL)
	{
		current = dequeue(&front, &rear);
		if (current->left == NULL)
		{
			while (front != NULL)
				dequeue(&front, &rear);
			return (current);
		}
		if (current->right == NULL)
		{
			while (front != NULL)
				dequeue(&front, &rear);
			return (current);
		}
		if (enqueue(&front, &rear, current->left) == 0)
		{
			while (front != NULL)
				dequeue(&front, &rear);
			return (NULL);
		}
		if (enqueue(&front, &rear, current->right) == 0)
		{
			while (front != NULL)
				dequeue(&front, &rear);
			return (NULL);
		}
	}
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the inserted node after heap reordering,
 *         or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node, *inserted, *current;
	int temp;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		if (new_node == NULL)
			return (NULL);
		*root = new_node;
		return (new_node);
	}
	parent = find_parent(*root);
	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else
	{
		parent->right = new_node;
	}
	current = new_node;
	inserted = new_node;
	while (current->parent != NULL && current->n > current->parent->n)
	{
		temp = current->n;
		current->n = current->parent->n;
		current->parent->n = temp;

		current = current->parent;
		inserted = inserted->parent;
	}
	return (inserted);
}
