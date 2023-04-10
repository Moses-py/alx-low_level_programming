#include "main.h"

/**
 * create_file - A function to create a file
 * @filename: A pointer referencing the name of the file to be created
 * @text_content: A pointer referencing a string to write to the file.
 * Return: return -1 if error else 1
 */
int create_file(const char *filename, char *text_content)
{
	int open_file, write_file, iterator = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (iterator = 0; text_content[iterator];)
			iterator++;
	}

	open_file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_file = write(o, text_content, iterator);

	if (open_file == -1 || write_file == -1)
		return (-1);

	close(open_file);

	return (1);
}
