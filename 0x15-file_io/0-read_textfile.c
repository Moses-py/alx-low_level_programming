#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - a function that reads the contents
 * of a text file and prints it to POSIX.
 * @filename: A pointer referencing the name of the file.
 * @letters: The number of letters
 * Return: return 0 if filename is NULL else,
 * return number of letters to be read and written
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *pAlloc_mem;
	ssize_t open_file;
	ssize_t write_file;
	ssize_t read_file;

	open_file = open(filename, O_RDONLY);
	if (open_file == -1)
		return (0);
	pAlloc_mem = malloc(sizeof(char) * letters);
	read_file = read(fd, buf, letters);
	write_file = write(STDOUT_FILENO, buf, t);

	free(pAlloc_mem);
	close(open_file);
	return (write_file);
}
