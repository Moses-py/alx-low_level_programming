#include "main.h"
/**
 * _isalpha - checks for alphabetic character.
 * @c:char that is checked
 *
 * Return: 1 if character is letter, lowercase or uppercase, 0 if otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
