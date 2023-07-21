#include "shell.h"

/**
 * my_getenv - function that searches the environment
 * list to find the environment
 * @name: is a string representing the name of the environment.
 * @environ: array of character pointers to the environment strings.
 *  * Return: pointer to the value.
 */

char *my_getenv(const char *name)
{
	char *currentvar;
	size_t len;
	int i;


	if (name == NULL || my_strlen(name) == 0)
	{	return (NULL); }
	for (i = 0; environ[i] != NULL; i++)
	{	currentvar = environ[i];
		len = my_strlen(name);
		if (my_strncmp(currentvar, name, len) == 0 && currentvar[len] == '=')
		{
			return (currentvar + len + 1);
		}
	}

	return (NULL);
}




