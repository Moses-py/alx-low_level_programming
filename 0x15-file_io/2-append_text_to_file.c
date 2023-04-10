#include "main.h"

/**
 * append_text_to_file - a function that
 * appends text to the end of a file.
 * @filename: A pointer referencing the name of the file.
 * @text_content: string to be added.
 * Return: return 1 else returns -1 if error
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int open, write, iterator = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (iterator = 0; text_content[iterator];)
			iterator++;
	}

	open = open(filename, O_WRONLY | O_APPEND);
	write = write(open, text_content, iterator);

	if (open == -1 || write == -1)
		return (-1);

	close(open);

	return (1);
}
