#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, in_length = 0;
	va_list arg_list;

	va_start(arg_list, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c' || format[i + 1] == 's' ||
			format[i + 1] == 'r' || format[i + 1] == 'R' ||
			format[i + 1] == '%')
				in_length = switch_char(arg_list, format[i + 1], in_length);
			else if (format[i + 1] != '\0')
				in_length = switch_num(arg_list, format[i + 1], in_length);
			i++;
		}
		else
		{
			_putchar(format[i]);
			in_length++;
		}
	}
	va_end(arg_list);
	return (in_length);
}
