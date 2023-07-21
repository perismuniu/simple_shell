#include "shell.h"

/**
 * printEnvironment - function that prints the environment variables
 *
 */

void printEnvironment(void)
{
	char **env = environ;
	size_t len;

	while (*env != NULL)
	{
		len = strlen(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
