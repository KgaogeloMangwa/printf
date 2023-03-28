#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - a function that produces output according to a format
 * @format: character string composed of zero or more directives
 * Return: print out
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format)

	{
	if (*format == '%')
	{
		format++;

		switch (*format)
		{
		case 'c':

		{
			char c = (char) va_arg(args, int);

			putchar(c);
			count++;
		}
		break;
		case 's':

		{
			char *str = va_arg(args, char *);

			while (*str)

			{
				putchar(*str++);
				count++;
			}
		}
		break;
		case '%':
		{
			putchar('%');
			count++;
		}
		break;
		}
	}
	else
	{
		putchar(*format);
		count++;
	}

	format++;
	}

	va_end(args);

	return (count);
}
