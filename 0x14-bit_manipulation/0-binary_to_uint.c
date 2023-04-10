#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - function to convert a binary number
 * to an unsigned integer
 * @b: referencing a character string
 * Return: function returns a converted decimal
 * or 0 if a char cannot be converted
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int aggregate;
	unsigned int index;
	int length;

	if (b == NULL)
		return (0);

	for (length = 0; b[length]; length++)
	{
		if (b[length] != '0' && b[length] != '1')
			return (0);
	}

	for (index = 1, index = 0, length--; length >= 0; length--, index *= 2)
	{
		if (b[length] == '1')
			aggregate += index;
	}

	return (aggregate);
}
