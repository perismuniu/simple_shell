#include "shell.h"


/**
 * signal_handler - function that handles (ctrl + c) single.
 * @signum: the recieved signal number.
 */


void signal_handler(int signum)
{
	write(STDOUT_FILENO, "\n$ ", 3);
	my_printf("Signal received: %d\n", signum);
	fflush(stdout);
}

/**
 * main - Entry point of the program.
 * This program  supports both interactive and non-interactive modes
 * of as shell program.
 * Return: (0) on success.
 */

int main(void)
{
	char *input = NULL;
	size_t inputsize = 0;
	ssize_t bytesread;
	char *token;

	signal(SIGINT, signal_handler);
	if (!isatty(fileno(stdin)))
	{	bytesread = getline(&input, &inputsize, stdin);
		if (bytesread == -1)
		{	perror("getline");
			return (1); }
		input[bytesread - 1] = '\0';
		token = my_strtok(input, ";");
		while (token != NULL)
		{	executecmd(token);
			token = my_strtok(NULL, ";"); }
		free(input);
		return (0);
	}
	while (1)
	{	write(STDOUT_FILENO, "$ ", 2);
		bytesread = getline(&input, &inputsize, stdin);
		if (bytesread == -1)
		{	perror("getline");
			break;
		}
		if (bytesread == 0)
		{	break; }
		input[bytesread - 1] = '\0';
		token = my_strtok(input, ";");
		while (token != NULL)
		{	executecmd(token);
			token = my_strtok(NULL, ";");
		}
		if (my_strcmp(input, "exit") == 0)
		{	free(input);
			exit_shell(0); }
	}
	free(input);
	return (0);
}
