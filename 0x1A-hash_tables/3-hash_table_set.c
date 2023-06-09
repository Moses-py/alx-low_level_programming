#include "hash_tables.h"

/**
 * hash_table_set - Function to update an element in a hash table.
 * @ht: A pointer to the hash table in memory.
 * @key: The key to add - non-empty string.
 * @value: The value representing the key.
 *
 * Return: 0 if fail, else 1
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *temp_value;
	unsigned long int desc, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	temp_value = strdup(value);
	if (temp_value == NULL)
		return (0);

	desc = key_index((const unsigned char *)key, ht->size);
	for (i = desc; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = temp_value;
			return (1);
		}
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(temp_value);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = temp_value;
	new_node->next = ht->array[desc];
	ht->array[desc] = new_node;

	return (1);
}
