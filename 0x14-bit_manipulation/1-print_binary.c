#include "main.h"
#include <stdio.h>

/**
 * print_binary - a function to print a
 * binary representation of a decimal
 * @n: referencing the decimal number
 * to be printed as a binary digit
 */
void print_binary(unsigned long int n)
{
	unsigned long int val_holder;
	int places_next;

	if (n == 0)
	{
		printf("0");
		return;
	};

	for (val_holder = n, places_next = 0; (val_holder >>= 1) > 0; places_next++)
	;

	for (; places_next >= 0; places_next--)
	{
		if ((n >> places_next) & 1)
			printf("1");
		else
			printf("0");
	};
}
