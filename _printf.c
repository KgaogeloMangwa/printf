#include "holberton.h"

int (*printer_aux(char flag))(va_list);

void _print_arg(char c, va_list args, int *count);

/**
 * _printf - produces output according to a format.
 * @format: format specifier.
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
<<<<<<< HEAD
	va_list args;

	int count = 0;

	va_start(args, format);


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
=======
	va_list arg;
	int i, printed_chars = 0;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(arg, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else if (format[i + 1] == '\0')
			return (-1);
		else if (format[i + 1] == '%')
		{
			_putchar(format[i]);
			printed_chars++;
			i++;
		}
		else if (printer_aux(format[i + 1]) != NULL)
		{
			printed_chars = printed_chars + printer_aux(format[i + 1])(arg);
			i++;
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
>>>>>>> a4af99d0dc1de17155abebe5d658030d1ae9f103
	}
	va_end(arg);

	return (printed_chars);
}

/**
 * printer_aux - auxiliar function for print with a specific format.
 * @flag: format specifier
 * Return: pointer to format function or NULL.
 */
int (*printer_aux(char flag))(va_list)
{
<<<<<<< HEAD

	switch (c)
	{
	case 'c':
		{
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
			(*count)++;
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
=======
	printer_t arr[] = {
		{'c', print_c},
		{'s', print_s},
		{'i', print_i},
		{'d', print_i},
		{'b', print_b},
		{'u', print_u},
		{'o', print_o},
		{'x', print_x},
		{'X', print_X},
		{'r', print_r},
		{'R', print_R},
		{'\0', NULL}
	};
	int i;

	for (i = 0; arr[i].flag != '\0'; i++)
		if (flag == arr[i].flag)
			break;

	return (arr[i].function);
>>>>>>> a4af99d0dc1de17155abebe5d658030d1ae9f103
}
