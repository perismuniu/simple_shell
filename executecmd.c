#include "shell.h"

/**
 * executecmd - function that executes command.
 * @cmd: Pointer to the command to be executed.
 */

void executecmd(const char *cmd)
{
	char *val, *token, *var, *directory, *status_str;
	int status;
	int overwrite = 0;

	if (my_strncmp(cmd, "exit", 4) == 0)
	{	status_str = (char *)cmd + 4;
		if (*status_str == '\0')
		{	exit_shell(0); }
		else
		{	status = my_atoi(status_str);
			exit(status); }
	}
	else if (my_strcmp(cmd, "env") == 0)
	{	printEnvironment(); }
	else if (my_strncmp(cmd, "setenv", 6) == 0)
	{	token = my_strtok((char *)cmd + 6, " ");
		var = token;
		token = my_strtok(NULL, " ");
		val = token;
		if (var != NULL && val != NULL)
		{		set_env(var, val, overwrite); }
		else
		{		write(STDERR_FILENO, "Invalid setenv command\n", 24); } }
	else if (my_strncmp(cmd, "unsetenv", 8) == 0)
	{	token = my_strtok((char *)cmd + 8, " ");
		var = token;
		if (var != NULL)
		{	unset_env(var); }
		else
		{		write(STDERR_FILENO, "Invalid unsetenv command\n", 26); } }
	else if (my_strncmp(cmd, "cd", 2) == 0)
	{	token = my_strtok((char *)cmd + 2, " ");
		directory = token;
		if (directory != NULL)
		{	change_directory(directory); }
		else
		{	change_directory(NULL); } }
	else
	{	path(cmd);	} }
