#include "shell.h"

/**
 * my_strncmp - function that compares two strings up to specified length.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * @n: max characters to compare.
 * Return: 0 if both strings are equal.
 */

int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((int)(unsigned char)(*s1) - (int)(unsigned char)(*s2));
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
