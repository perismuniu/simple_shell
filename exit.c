#include "shell.h"

/**
 * exit_shell - function that exits the shell.
 */

void exit_shell(void)
{
	write(STDOUT_FILENO, "Shell exited...\n", 16);

	exit(0);
}
