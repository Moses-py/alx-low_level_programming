#include "main.h"
#include <stdio.h>

/**
 * flip_bits - with the flip_bits function
 * one can convert a decimal to another
 * @n: initial decimal
 * @m: second decimal
 * Return: returns the number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bit_difference;
	int flipped_counter;

	bit_difference = n ^ m;
	flipped_counter = 0;

	while (bit_difference)
	{
		flipped_counter++;
		bit_difference &= (bit_difference - 1);
	}

	return (flipped_counter);
}
