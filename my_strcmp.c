#include "shell.h"

/**
 *my_strcmp - function that compares two strings s1 and s2.
 *@s1: Pointer to the first string.
 *@s2: Pointer to the second string.
 *Return: An integer less than, equal to or greater than zero.
 */


int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
