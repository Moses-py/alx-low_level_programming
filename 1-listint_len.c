#include "lists.h"

/**
 * listint_len: A function that return the number of iterables in a linked list
 * @h: pointer to the iterable list of type listint_t
 *
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h) {
	size_t list_item = 0;

	while(h) {
		list_item++;
		h= h -> next;
	}

	return (list_item);
}

