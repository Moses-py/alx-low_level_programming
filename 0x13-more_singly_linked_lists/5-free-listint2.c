#include "lists.h"

/**
 * free_listint2 - A function that sets the head to NULL
 * @head: A pointer to the start of the list
 */
 
void free_listint2(listint_t **head)
{
	listint_t *hold_item;

	if (head == NULL)
		return;

	while (*head)
	{
		hold_item = (*head) -> next;
		free(*head);
		*head = hold_item;
	}

	*head = NULL;
}
