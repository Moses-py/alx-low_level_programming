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
	int open_file, write_file, iterator = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (iterator = 0; text_content[iterator];)
			iterator++;
	}

	open_file = open(filename, O_WRONLY | O_APPEND);
	write_file = write(open_file, text_content, iterator);

	if (open_file == -1 || write_file == -1)
		return (-1);

	close(open_file);

	return (1);
}
