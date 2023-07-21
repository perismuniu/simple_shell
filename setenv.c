#include "shell.h"

/**
 * set_env - function that sets the environment variable.
 * @var: Pointer to the name of the environment variable.
 * @val: Pointer to the value of the environment variable.
 */

void set_env(const char *var, const char *val)
{
	if (setenv(var, val, 1) != 0)
	{
		write(STDERR_FILENO, "Failed to set environment variable\n", 34);
	}
}
