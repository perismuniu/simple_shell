#include "shell.h"
/**
 * my_strchr - function that locates the first occurence
 * of a character in a string
 * @s: The string that is to e searched.
 * @c: The characteer to be located.
 * Return: the pointer to the first occurence of
 * the character or NULL if not found.
 */

char *my_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
