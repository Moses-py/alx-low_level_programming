#include "lists.h"

/**
 * add_nodeint_end: A function to add a new node at the end of a linked list
 * @head: A pointer referencing the first element in the linked list
 * @n: A data to be inserted into the added element
 *
 * Return: pointer to the new node, or NULL if it fails
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *added_node;
	listint_t *temp = *head;

	added_node = malloc(sizeof(listint_t));
	if (!added_node)
		return (NULL);

	added_node -> n = n;
	added_node -> next = NULL;

	if (*head == NULL)
	{
		*head = added_node;
		return (added_node);
	}

	while (temp -> next)
		temp = temp -> next;

	temp -> next = added_node;

	return (added_node);
}
