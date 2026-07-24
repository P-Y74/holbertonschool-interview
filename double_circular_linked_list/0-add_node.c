#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_node - creates a new list node
 * @str: string to duplicate
 *
 * Return: pointer to the new node, or NULL on failure
 */
List *create_node(char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->prev = NULL;
	new->next = NULL;

	return (new);
}

/**
 * add_node_end - adds a new node to the end of a double circular linked list
 * @list: double pointer to the list head
 * @str: string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;
	List *last;

	if (list == NULL || str == NULL)
		return (NULL);

	new = create_node(str);
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	new->next = *list;
	new->prev = last;
	last->next = new;
	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - adds a new node to the beginning of a double circular list
 * @list: double pointer to the list head
 * @str: string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;
	List *last;

	if (list == NULL || str == NULL)
		return (NULL);

	new = create_node(str);
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;

	new->next = *list;
	new->prev = last;
	last->next = new;
	(*list)->prev = new;
	*list = new;

	return (new);
}
