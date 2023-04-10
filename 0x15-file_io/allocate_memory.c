#include <stdio.h>
#include <stdlib.h>

/**
 * allocate_memory - A function that allocates 1024 bytes of memory in heap.
 * @file: A pointer to the file allocated_memory.
 * Return: returns a pointer to allocated memory location.
 */
char *allocate_memory(char *file)
{
	char *pAlloc_mem;

	pAlloc_mem = (char *) malloc(sizeof(char) * 1024);

	if (pAlloc_mem == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (pAlloc_mem);
}
