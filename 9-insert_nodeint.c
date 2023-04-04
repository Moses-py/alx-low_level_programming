#include "lists.h"

/**
 * insert_nodeint_at_index - Function to insert a new node into a linked list at a given position
 * @head: points to the first node/element
 * @idx: index position to insert new node
 * @n: data to populate new node
 *
 * Return: address of the new node, or NULL if failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int index;
	listint_t *item;
	listint_t *hold_item = *head;

	item = malloc(sizeof(listint_t));
	if (!item || !head)
		return (NULL);

	item -> n = n;
	item -> next = NULL;

	if (idx == 0)
	{
		item -> next = *head;
		*head = item;
		return (item);
	}

	for (index = 0; temp && index < idx; index++)
	{
		if (index == idx - 1)
		{
			item->next = hold_item -> next;
			hold_item -> next = item;
			return (item);
		}
		else
			hold_item = hold_item -> next;
	}

	return (NULL);
}
