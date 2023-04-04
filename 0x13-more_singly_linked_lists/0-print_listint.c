#include "lists.h"

/**
 * print_listint - This is a function that prints all elements
 * present in a linked list
 * @h: A pointer to the type of a single listint to be printed
 *
 * Return: number of nodes
 */

size_t print_listint (const listint_t *h)
{
	size_t list_item = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		list_item++;
		h = h->next;
	}

	return (list_item);
}

