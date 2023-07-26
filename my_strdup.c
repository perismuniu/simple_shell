#include "shell.h"

/** 
 * my_strdup - function that duplicates a string.
 * @str: the string to duplicate.
 * Return: new pointer allocation.
 */

char *my_strdup(const char *str)
{
	 size_t len, i;
	 char *new_str;

	 if (str == NULL)
	 {	 return (NULL); }
	 len = strlen(str) + 1;
	 new_str = (char *)malloc(len);
	  if (new_str != NULL)
	  {
		  for (i = 0; i < len; i++)
		  {
			  new_str[i] = str[i];
		  }
	  }
	  return (new_str);
}
