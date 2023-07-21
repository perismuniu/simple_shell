#include "shell.h"

/**
 * my_strlen - function calculates the length
 * of the string that is null-terminated.
 * @s: Pointer to the string.
 * Return: The string length.
 */

size_t my_strlen(const char *s)
{
	size_t length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
