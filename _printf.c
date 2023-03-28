#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: number of characters printed
 * (excluding the null byte used to end output to strings)
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
		_print_arg(*format, args, &count);
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

/**
 * _print_arg - prints a single argument based on the given
 * conversion specifier
 * @c: the conversion specifier to use
 * @args: the argument list to print
 * @count: pointer to the count of characters printed
 */
void _print_arg(char c, va_list args, int *count)
{
	switch (c)
	{
	case 'c':
	}
	char ch = (char) va_arg(args, int);

	putchar(ch);
	(*count)++;
	}
	break;

	case 's':
	{
		char *str = va_arg(args, char *);

		while (*str)
		{
			putchar(*str++);
			(*count)++
		}
	}
	break;
	case '%':
	{
		putchar('%');
		(*count)++;
	}
	break;
	}
}
