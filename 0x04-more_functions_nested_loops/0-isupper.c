#include "main.h"

/**
 * _isupper - A function that checks for uppercase character.
 * @c: An input character
 * Return: 1 if c is uppercase or 0 otherwise
 */

int _isupper(int c)
{
	char uppercase;
	int isCharUpper = 0;

	for (uppercase = 'A'; uppercase <= 'Z'; uppercase++)
	{
		if (c == uppercase)
			isCharUpper = 1;
	}
	return (isCharUpper);
}
