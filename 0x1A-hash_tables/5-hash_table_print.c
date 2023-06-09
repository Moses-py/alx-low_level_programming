#include "hash_tables.h"

/**
 * hash_table_print - Function to print a hash table.
 * @ht: A pointer to the hash table to be printed.
 *
 * Description: pairs are printed in the order
 * they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node_value;
	unsigned long int i;
	unsigned char flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (flag == 1)
				printf(", ");

			node_value = ht->array[i];
			while (node_value != NULL)
			{
				printf("'%s': '%s'", node_value->key, node_value->value);
				node_value = node_value->next;
				if (node_value != NULL)
					printf(", ");
			}
			flag = 1;
		}
	}
	printf("}\n");
}