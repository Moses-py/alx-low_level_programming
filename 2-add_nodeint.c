#include "lists.h"

/**
 * add_nodeint: A function to add a new node at the start of a linked list
 * @head: A pointer to the first node in the linked list
 * @n: A data to be inserted into the added node
 *
 * Return: A pointer to the address of the new element added, or NULL if unsuccessful
*/

listint_t *add_nodeint(listint_t **head, const int n){

	listint_t *added_node;

	added_node = malloc(sizeof(listint_t));
	if (!added_node)
		return (NULL);

	added_node -> n = n;
	added_node -> next = *head;
	*head = added_node;

	return (added_node);
}

