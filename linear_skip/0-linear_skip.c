#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to the first node containing value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start;
	skiplist_t *end;

	if (list == NULL)
		return (NULL);

	start = list;
	end = list;

	while (end->express != NULL)
	{
		start = end;
		end = end->express;

		printf("Value checked at index [%lu] = [%d]\n",
			   end->index, end->n);

		if (end->n >= value)
			break;
	}

	if (end->express == NULL && end->n < value)
	{
		start = end;
		while (end->next != NULL)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   start->index, end->index);

	while (start != NULL && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}
	return (NULL);
}
