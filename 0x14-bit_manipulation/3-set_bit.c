#include "main.h"

/**
 * set_bit - with the function set_bit one can set
 * a bit's value at a specified index to 1
 * @n: referencing a decimal referenced through a pointer
 * @index: the index position of the bit to change
 * Return: returns 1, else returns -1 if error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int iterator;

	if (index > 64)
		return (-1);

	for (iterator = 1; index > 0; index--, iterator *= 2)
		;
	*n += iterator;

	return (1);
}

