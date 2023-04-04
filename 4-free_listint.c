#include "lists.h"

/**
 * free_listint - A function that free a linked list
 * @head: Pointer to the list to be freed
 */

void free_listint(listint_t *head)
{
	listint_t *hold_item;

	while (head)
	{
		hold_item = head -> next;
		free(head);
		head = hold_item;
	}
}
