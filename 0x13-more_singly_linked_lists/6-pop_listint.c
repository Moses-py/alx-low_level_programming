#include "lists.h"

/**
 * pop_listint: Function to delete the top level node of a linked list
 * @head: A pointer to the head element in the list
 *
 * Return: deleted data or 0 if an empty list is present
 */

int pop_listint(listint_t **head)
{
	listint_t *hold_item;
	int item;

	if (!head || !*head)
		return (0);

	item = (*head) -> n;
	hold_item = (*head) -> next;
	free(*head);
	*head = hold_item;

	return (item);
}
