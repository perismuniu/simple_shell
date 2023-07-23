#include "shell.h"

/**
 * free_memory - funtion that frees memory.
 * @lineptr: pointer to the buffer.
 */

void free_memory(char *lineptr)
{
	free(lineptr);
}
