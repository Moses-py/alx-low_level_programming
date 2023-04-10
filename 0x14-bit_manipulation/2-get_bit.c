#include "main.h"
#include <stdio.h>

/**
 * get_bit - with the function get_bit, one can determine
 * a bit's value at a given index.
 * @n: referencing the number to be evaluated
 * @index: index of the bit starting from 0
 * Return: returns the digit value of a bit at the given
 * index, or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int temp_hold;

	if (index > 64)
		return (-1);

	temp_hold = n >> index;

	return (temp_hold & 1);
}
