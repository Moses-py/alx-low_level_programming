#include "lists.h"
#include <stdio.h>

/**
 * print_listint - This is a function that prints all elements
 * present in a linked list
 *
 * @h: A pointer to the type of a single listint to be printed
 *
 * Return: number of nodes
 */
size_t print_listint (const listint_t *h)
{
	size_t item = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		item++;
		h = h->next;
	}

	return (item);
}
