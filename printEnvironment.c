#include "shell.h"

/**
 * printEnvironment - function that prints the environment variables
 *
 */

void printEnvironment()
{
  char **env = environ;
  while (*env != NULL)
    {
      size_t len = strlen(*env);
      write(STDOUT_FILENO, *env, len);
      write(STDOUT_FILENO, "\n", 1);
      env++;
    }
}
