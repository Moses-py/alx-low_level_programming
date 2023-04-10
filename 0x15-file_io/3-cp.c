#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - copies content from and to a file.
 * @argc: argument count.
 * @argv: pointer array to the arguments.
 *
 * Return: return 0.
 */
int main(int argc, char *argv[])
{
	int copy_from, copy_to, read, write;
	char *alloc_mem;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	alloc_mem = allocate_memory(argv[2]);
	copy_from = open(argv[1], O_RDONLY);
	read = read(from, buffer, 1024);
	copy_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (copy_from == -1 || read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(alloc_mem);
			exit(98);
		}
		write = write(copy_to, alloc_mem, read);
		if (copy_to == -1 || write == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(alloc_mem);
			exit(99);
		}
		read = read(copy_from, alloc_mem, 1024);
		copy_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (read > 0);

	free(alloc_mem);
	close_file_descriptor(copy_from);
	close_file_descriptor(copy_to);

	return (0);
}
