#include "main.h"

/**
 * get_endianness - a function that checks the order
 * in which a sequence of bytes is stored in computer memory
 * Return: returns 0 if it's a big endian
 * or return 1 if it is a little endian
 */
int get_endianness(void)
{
	int order;

	order = 1;
	if (*(char *)&order == 1)
		return (1);
	else
		return (0);
}
