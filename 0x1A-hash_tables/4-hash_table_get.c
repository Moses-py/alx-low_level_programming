#include "hash_tables.h"

/**
 * hash_table_get - function to retrieve the value associated with
 * to a key in hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value.
 *
 * Return: Key mismatch -null else value
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node_value;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);
	if (i >= ht->size)
		return (NULL);

	node_value = ht->array[i];
	while (node_value && strcmp(node_value->key, key) != 0)
		node_value = node_value->next;

	return ((node_value == NULL) ? NULL : node_value->value);
}
