#include "lists.h"

/**
 * get_nodeint_at_index: A function that returns the index of a node in a linked list
 * @head: first element/node in the list
 * @index: index value of the node to be returned
 *
 * Return: A pointer to a specific node, or NULL if such node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int item = 0;
	listint_t *hold_item = head;

	while (hold_item && item < index)
	{
		hold_item = hold_item -> next;
		item++;
	}
	
   	if (hold_item)
       		 return hold_item;
   	else 
        	return NULL;
}
