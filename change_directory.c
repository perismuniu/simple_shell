#include "shell.h"
#define INPUT_SIZE 256

/**
 * change_directory - function that changes the current working directory.
 * @path: Pointer to the path of the directory to change to.
 */

void change_directory(const char *path)
{
	char current_dir[INPUT_SIZE];

	if (path == NULL || my_strlen(path) == 0)
	{	path = my_getenv("HOME"); }
	else if (my_strcmp(path, "-") == 0)
	{	path = my_getenv("OLDPWD"); }
	if (path == NULL)
	{	write(STDERR_FILENO, "Failed to change directory\n", 27);
		return;
	}
	if (chdir(path) == 0)
	{	set_env("OLDPWD", my_getenv("PWD"));
		getcwd(current_dir, sizeof(current_dir));
		set_env("PWD", current_dir);
	}
	else
	{	write(STDERR_FILENO, "Failed to change directory\n", 27); }
}
