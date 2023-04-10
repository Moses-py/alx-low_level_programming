#ifndef FILE_IO_H
#define FILE_IO_H

#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
char *allocate_memory(char *file);
void close_file_descriptor(int FD);

#endif

