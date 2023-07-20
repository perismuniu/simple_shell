#include "shell.h"
#define BUFFER_SIZE
/**
 * custom_getline - function that reads a line of input from standard input.
 * Return: Number of characters read, or (-1) on error or end of file.
 */

char *custom_getline(void)
{
	size_t n = BUFFER_SIZE;
	char *buffer = malloc(sizeof(char) * n);
	int read_num, position = 0;
	char *new_buffer;

	if (!buffer)
	{	return (NULL); }
	while (1)
	{	read_num = read(STDIN_FILENO, buffer + position, BUFFER_SIZE - position);
		if (read_num == -1)
		{	free(buffer);
			return (NULL);
		}
		if (read_num == 0)
		{	break; }
		position += read_num;
		if (position >= n)
		{	n *= 2;
			new_buffer = malloc(sizeof(char) * n);
			if (new_buffer == NULL)
			{	free(buffer);
				return (NULL);
			}
			else
			{	my_strcpy(new_buffer, buffer);
				free(buffer);
				buffer = new_buffer;
			}
		}
		if (buffer[position - 1] == '\n')
		{	buffer[position - 1] == '\0';
			break;
		}
	}
	if (position == 0 && buffer != NULL)
	{	free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

