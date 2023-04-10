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
	char *pAlloc_mem;
	
	pAlloc_mem = malloc(letters * sizeof(char));
       	open = open(filename, O_RDONLY);
	read = read(open, pAlloc_mem, letters);

	if (open == -1 || read == -1 || write == -1 || write != read)
	{
		free(pAlloc_mem);
		return (0);
	}
	write = write(STDOUT_FILENO, pAlloc_mem, read);

	free(pAlloc_mem);
	close(open);

	return (write);
}
