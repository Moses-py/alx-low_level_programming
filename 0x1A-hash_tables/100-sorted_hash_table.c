#include "hash_tables.h"

/**
 * shash_table_create - Function to create a sorted hash table.
 * @size: The size of new_node hash table.
 *
 * Return: If error - NULL else,
 * pointer to the new_node sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_table;
	unsigned long int i;

	hash_table = malloc(sizeof(shash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->size = size;
	hash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (hash_table->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;
	hash_table->shead = NULL;
	hash_table->stail = NULL;

	return (hash_table);
}

/**
 * shash_table_set - FUnction to add an element to a sorted hash table.
 * @hash_table: A pointer to the hash table.
 * @key: The key to add - non-empty string
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0, otherwise - 1.
 */
int shash_table_set(shash_table_t *hash_table, const char *key, const char *value)
{
	shash_node_t *new_node, *temp;
	char *temp_value;
	unsigned long int index;

	if (hash_table == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	temp_value = strdup(value);
	if (temp_value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, hash_table->size);
	temp = hash_table->shead;
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = temp_value;
			return (1);
		}
		temp = temp->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(temp_value);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(temp_value);
		free(new_node);
		return (0);
	}
	new_node->value = temp_value;
	new_node->next = hash_table->array[index];
	hash_table->array[index] = new_node;

	if (hash_table->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		hash_table->shead = new_node;
		hash_table->stail = new_node;
	}
	else if (strcmp(hash_table->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = hash_table->shead;
		hash_table->shead->sprev = new_node;
		hash_table->shead = new_node;
	}
	else
	{
		temp = hash_table->shead;
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		new_node->sprev = temp;
		new_node->snext = temp->snext;
		if (temp->snext == NULL)
			hash_table->stail = new_node;
		else
			temp->snext->sprev = new_node;
		temp->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Function to retrieve the value associated with
 * a key in a hash table.
 * @hash_table: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: unmatched key - NULL, else,
 * the value associated with key in hash_table.
 */
char *shash_table_get(const shash_table_t *hash_table, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (hash_table == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, hash_table->size);
	if (index >= hash_table->size)
		return (NULL);

	node = hash_table->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @hash_table: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *hash_table)
{
	shash_node_t *node;

	if (hash_table == NULL)
		return;

	node = hash_table->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @hash_table: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *hash_table)
{
	shash_node_t *node;

	if (hash_table == NULL)
		return;

	node = hash_table->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @hash_table: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *hash_table)
{
	shash_table_t *head = hash_table;
	shash_node_t *node, *temp;

	if (hash_table == NULL)
		return;

	node = hash_table->shead;
	while (node)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}

	free(head->array);
	free(head);
}