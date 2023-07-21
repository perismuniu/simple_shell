#include "shell.h"

/**
 * unset_env - function that unsets an environment variable.
 * @var: Pointer to the name of the environment variable.
 */

void unset_env(const char *var)
{
	if (unsetenv(var) != 0)
	{
		write(STDERR_FILENO, "Failed to unset environment variable\n", 36);
	}
}
