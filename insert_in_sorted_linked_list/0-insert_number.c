#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: Pointer to the pointer of the head of the list
 * @number: The integer value to insert
 *
 * This function inserts a new node containing @number into a
 * singly linked list that is already sorted in ascending order.
 * The list remains sorted after insertion.
 *
 * The function handles the following cases:
 * - If the list is empty, the new node becomes the head.
 * - If the new value is smaller than or equal to the head value,
 *   the new node is inserted at the beginning of the list.
 * - Otherwise, the list is traversed to find the correct position
 *   where the new value fits, and the node is inserted accordingly.
 *
 * Return: Address of the newly created node, or NULL on failure.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}

	if ((*head)->n >= number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	current = *head;

	while (current->next && current->next->n < number)
		current = current->next;

	new->next = current->next;
	current->next = new;

	return (new);
}
