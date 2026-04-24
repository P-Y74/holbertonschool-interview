#include <stdio.h>
#include "lists.h"

/**
 * reverse_list - Reverses a singly linked list
 * @head: Pointer to the head of the list
 *
 * This function reverses the order of nodes in a singly linked list.
 *
 * Return: Pointer to the new head of the reversed list
 */
static listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *next;
    listint_t *current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 *
 * This function determines whether a singly linked list reads the same
 * forwards and backwards. It finds the middle of the list, reverses the
 * second half, and compares both halves node by node.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *second_half, *first, *second;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return (1);

    slow = *head;
    fast = *head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    second_half = reverse_list(slow);
    first = *head;
    second = second_half;

    while (second != NULL)
    {
        if (first->n != second->n)
            return (0);
        first = first->next;
        second = second->next;
    }
    return (1);
}