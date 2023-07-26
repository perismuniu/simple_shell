#include "shell.h"

/**
 * set_env - function that sets the environment variable.
 * @var: Pointer to the name of the environment variable.
 * @val: Pointer to the value of the environment variable.
 * Return: (0) on success and (-1) if there's an error
 */

int set_env(const char *name, const char *value, int overwrite)
{
	char *existing_value;
	size_t name_length;
	size_t value_length;
	size_t env_length;
	char *new_env;

	if (name == NULL || name[0] == '\0' || my_strchr(name, '=') != NULL)
	{	return( -1); }
	if (value == NULL)
	{	return( -1); }
	existing_value = my_getenv(name);
	if (existing_value != NULL && overwrite == 0)
	{	return (0); }
	name_length = my_strlen(name);
	value_length = my_strlen(value);
	env_length = name_length + value_length + 2;
	new_env = (char *)malloc(env_length);
	if (new_env == NULL)
	{	return( -1); }
	my_snprintf(new_env, env_length, "%s=%s", name, value);
	if (putenv(new_env) != 0)
	{	free(new_env);
		return( -1);
	}
	free(new_env);
	return (0);
}

