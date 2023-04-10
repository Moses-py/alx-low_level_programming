#include "main.h"
#include <stdio.h>

/**
 * clear_bit - with the clear_bit function,
 * one can reset the value of a bit to 0 at a specific index
 * @n: a pointer referencing the decimal to change
 * @index: the index position
 * Return: return 1, else return -1 if an error occurs
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int iterator;
	unsigned int val_holder;

	if (index > 64)
		return (-1);
	val_holder = index;
	for (iterator = 1; val_holder > 0; iterator *= 2, val_holder--)
	;

	if ((*n >> index) & 1)
		*n -= iterator;

	return (1);
}
