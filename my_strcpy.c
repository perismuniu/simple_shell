#include "shell.h"

/**
 * my_strcpy - function that copies string from source to destination.
 * @des: Pointer to the destination string.
 * @src: Pointer to the source string.
 * Return: The pointer to the destination string.
 */

char* my_strcpy(char* des, const char* src)
{
  char* ptr = des;

  while (*src != '\0')
    {
      *ptr++ = *src++;
    }
  *ptr = '\0';
  return (des);
}
