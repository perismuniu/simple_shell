#include "shell.h"

/**
 * unset_env - function that unsets an environment variable.
 * @var: Pointer to the name of the environment variable.
 */

int unset_env(const char *var)
{
	size_t varLen;
	char **src;
	char **dst;
	char **env;

	if (var == NULL || *var == '\0' || my_strchr(var, '=') != NULL)
	{	return (-1); }
	varLen = my_strlen(var);
	for (env = environ; *env; ++env)
	{
		if (my_strncmp(*env, var, varLen) == 0 && (*env)[varLen] == '=')
		{
			src = env;
			dst = env + 1;
			while (*src)
			{
				*src = *dst;
				++src;
				++dst;
			}
			free(*env);
			return (0);
		}
	}
	return (-1);
}
