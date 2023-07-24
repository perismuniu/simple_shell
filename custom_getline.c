#include "shell.h"

/**
 * custom_getline - function that reads a line of input from standard input.
 * @lineptr: pointer to the buffer.
 * @n: pointer to the variable that will be updated.
 * Return: Number of characters read, or (-1) on error or end of file.
 */

ssize_t custom_getline(char **lineptr, size_t *n)
{
	const size_t buffersize = 128;
	const char delim = '\n';
	size_t i = 0;
	size_t bytesread;
	char ch, *tmp;

	if (lineptr == NULL || n == NULL)
	{	return (-1); }
	if (*lineptr == NULL)
	{	*n = buffersize;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{	 return (-1); }
	}
	while (1)
	{
		bytesread = read(STDIN_FILENO, &ch, sizeof(ch));
		if (bytesread <= 0)
		{
			if (i == 0 && bytesread == 0)
			{
				free(*lineptr);
				return (-1); }
			break;
		}
		if (i >= *n - 1)
		{	*n *= 2;
			*lineptr = (char *)malloc(*n);
			tmp = (char *)malloc(*n);
			if (tmp == NULL)
			{	free(*lineptr);
				return (-1);	
			}
			my_strcpy(tmp, *lineptr);
			free(*lineptr);
			*lineptr = tmp;
		}
		(*lineptr)[i++] = ch;
		if (ch == delim)
		{	 break; }
	}
	(*lineptr)[i] = '\0';
	return (i);
}
