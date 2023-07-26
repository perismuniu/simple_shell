#include "shell.h"

/**
 * exit_shell - function that exits the shell.
 * @status: the status code to exit the shell
 */

void exit_shell(int status)
{
	const char *message = NULL;
	int signal_number;

	switch (status)
	{
		case 0:
			message = "Shell exited successfully.\n";
			break;
		case 126:
			message = "Command found but is not executable.\n";
			break;
		case 127:
			message = "Command not found.\n";
			break;
		default:
			if (status > 0 && status <= 125)
			{
				my_printf("Shell exited with status %d.\n", status);
			}
			else if (status > 128 && status < 256)
			{
				signal_number = status - 128;
				my_printf("Shell exited due to signal %d: %s\n",
						signal_number, strsignal(signal_number));
			}
			else
			{
				my_printf("Unknown error: %s\n", strerror(errno));
			}
			break;
	}
	if (message != NULL)
	{
		my_printf("%s", message);
	}
	exit(status);
}

