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
	{	path = getenv("HOME"); }
	else if (my_strcmp(path, "-") == 0)
	{	path = getenv("OLDPWD"); }
	if (path == NULL)
	{	write(STDERR_FILENO, "Failed to change directory\n", 27);
		return;
	}
	if (chdir(path) == 0)
	{	setenv("OLDPWD", getenv("PWD"));
		getcwd(current_dir, sizeof(current_dir));
		setenv("PWD", current_dir);
	}
	else
	{	write(STDERR_FILENO, "Failed to change directory\n", 27); }
}
