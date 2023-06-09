#include "hash_tables.h"

/**
 * hash_djb2 - A function implementing the djb2 algorithm.
 * @str: The string to be hashed.
 *
 * Return: The calculated hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash_value;
	int c;

	hash_value = 5381;
	while ((c = *str++))
		hash_value = ((hash_value << 5) + hash_value) + c;

	return (hash_value);
}