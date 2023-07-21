#include "shell.h"

/**
 * my_atoi - function that converts a string to an interger.
 * @str: Pointer to the string.
 * Return: converted interger.
 */

int my_atoi(const char *str)
{
	int outcome = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		outcome = outcome * 10 + (str[i] - '0');
		i++;
	}
	return (outcome * sign);
}
