#include <unistd.h>

/**
 * _putchar - a function that writes a character to stdout
 * @c: refrences the character to print
 *
 * Return: 1, and -1 if error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
