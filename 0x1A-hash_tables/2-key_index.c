#include "hash_tables.h"

/**
 * key_index - Function to get index at which a key/value
 *      pair is stored in the table array
 * @key: The key pointing to index.
 * @size: The size of the of the hash table.
 *
 * Return: The index of the key.
 * Description: Function that uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
