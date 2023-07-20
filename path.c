#include "shell.h"

/**
 * path - function that executes command in the simple shell.
 * @cmd: Command pointer to be executed.
 * Return: The exit status of command on success and (-1) on failure.
 */

int path(const char *cmd)
{
	pid_t pid;
	int status;
	int len;
	char message[50];
	char *argument[4];

	pid = fork();
	if (pid == -1)
	{	write(STDERR_FILENO, "fork error\n", 12);
		return (-1);
	}
	else if (pid == 0)
	{	argument[0] = "/bin/sh";
		argument[1] = "-c";
		argument[2] = (char *)cmd;
		argument[3] = NULL;
		execve("/bin/sh", argv, NULL);
		write(STDERR_FILENO, "execve error\n", 13);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			write(STDERR_FILENO, "waitpid error\n", 14);
			return (-1);
		}
		if (WIFEXITED(status))
		{	return (WEXITSTATUS(status)); }
		else if (WIFSIGNALED(status))
		{	len = my_snprintf(message, sizeof(message),
				"Child process terminated by signal %d\n", WTERMSIG(status));
			write(STDOUT_FILENO, message, len);
			return (-1);
		}
		else
		{	write(STDERR_FILENO, "Child process terminated abnormally\n", 35);
			return (-1);
		}
	}
}
