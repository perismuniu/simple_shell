#include "shell.h"

/**
 * my_printf - customized implementation of printf function
 * Return: Number of characters to the standard output
 */

int my_printf(const char *format, ...)
{
  char buffer[1024];
  int len;
  va_list args;

  va_start(args, format);

  len = vsnprintf(buffer, sizeof(buffer), format, args);
  write(1, buffer, len);
  va_end(args);

  return len;
}

int my_snprintf(char* str, size_t size, const char* format, ...)
{
  int rersult;
  va_list args;
  va_start(args, format);
  result = vsnprintf(str, size, format, args);
  va_end(args);
  return result;
}
