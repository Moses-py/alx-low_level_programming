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
	unsigned int aggregate = 0;
	unsigned int index;
	int iterator;

	if (b == NULL)
		return (0);

	for (iterator = 0; b[iterator]; iterator++)
	{
		if (b[iterator] != '0' && b[iterator] != '1')
			return (0);
	}

	for (index = 1, iterator--; iterator >= 0; iterator--, index *= 2)
	{
		if (b[iterator] == '1')
			aggregate += index;
	}

	return (aggregate);
}
