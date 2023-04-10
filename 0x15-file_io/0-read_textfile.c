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
	ssize_t open, read, write;
	char *pAlloc_mem = NULL;

	if (filename == NULL)
		return (0);

	pAlloc_mem = (char *) malloc(letters * sizeof(char));
	if (pAlloc_mem == NULL)
		return (0);

	open = open(filename, O_RDONLY);
	read = read(o, pAlloc_mem, letters);
	write = write(STDOUT_FILENO, pAlloc_mem, r);

	if (open == -1 || read == -1 || write == -1 || write != read)
	{
		free(pAlloc_mem);
		return (0);
	}

	free(pAlloc_mem);
	close(open);

	return (write);
}
