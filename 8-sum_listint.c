#include "lists.h"

/**
 * sum_listint - A function to return the sum of all the iterables in a list of type listint_t
 * @head: first element/ in the list
 *
 * Return: sum of iterables in the list or 0 if list is empty
 */
 
int sum_listint(listint_t *head)
{
	int resultant = 0;
	listint_t *hold_item = head;

	while (hold_item)
	{
		resultant += hold_item -> n;
		hold_item = hold_item -> next;
	}

	return (resultant);
}

