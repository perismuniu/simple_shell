#include "shell.h"

/**
 * my_strtok - function that breaks a string into a sequence of tokens.
 * @str: The pointer to the input string.
 * @delim: Pointer to the delimiter string.
 * Return: Pointer to next token found, or NULL if token not found.
 */

char *my_strtok(char *str, const char *delim)
{
	static char *buf;
	char *token_start;
	int token_len, delim_len, is_delim, i;

	if (str != NULL)
	{	buf = str; }
	if (buf == NULL || buf == '\0')
	{	return (NULL); }
	token_start = buf;
	token_len = 0;
	delim_len = my_strlen(delim);
	while (*buf != '\0')
	{	is_delim = 0;
		for (i = 0; i < delim_len; i++)
		{
			if (*buf == delim[i])
			{	is_delim = 1;
				break;
			}
		}
		if (is_delim)
		{	*buf = '\0';
			buf++;
			break;
		}
		buf++;
		token_len++;
	}
	if (token_len == 0)
	{
		return (my_strtok(NULL, delim));
	}
	return (token_start);
}
