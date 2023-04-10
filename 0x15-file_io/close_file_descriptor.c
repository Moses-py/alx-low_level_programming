#include <stdio.h>
#include <stdlib.h>

/**
 * close_file_descriptor - function that closes the file.
 * @FD: pointer to the file to be closed.
 */
void close_file_descriptor(int FD)
{
	int close;

	close = close(FD);

	if (close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close FD %d\n", FD);
		exit(100);
	}
}
