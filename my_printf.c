#include "shell.h"

/**
 * my_printf - customized implementation of printf function
 * @format: format string specifying the output formart.`
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
	return (len);
}

/**
 *my_snprintf - function that safely stores and formats a formatted
 *string into a buffer
 *@str:buffer storing the output string.
 *@size: maximum number of characters to write into buffer.
 *@format: format string specifying the output formart.
 *Return: (result)
 */

int my_snprintf(char *str, size_t size, const char *format, ...)
{
	int result;
	va_list args;

	va_start(args, format);
	result = vsnprintf(str, size, format, args);
	va_end(args);
	return (result);
}
