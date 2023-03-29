#include "main.h"

int switch_char(va_list arg, char symbol, int in_length);
/**
 * switch_num - Helper function that holds the switch statement
 * and calls certain functions depending on the symbol
 * This function deals with numbers
 * @arg: va_list passed in from printf.c
 * @symbol: The letter passed in from printf.c
 * @in_length: Variable that holds the number of char printed
 * Return: The number of characters printed
 */
int switch_num(va_list arg, char symbol, int in_length)
{
	switch (symbol)
	{
		case 'b':
			print_num(arg, &in_length, symbol);
			break;
		case 'd':
		case 'i':
			print_num(arg, &in_length, symbol);
			break;
		case 'u':
			print_num(arg, &in_length, symbol);
			break;
		case 'o':
			print_num(arg, &in_length, symbol);
			break;
		case 'x':
			print_num(arg, &in_length, symbol);
			break;
		case 'X':
			print_num(arg, &in_length, symbol);
			break;
		default:
			_putchar('%');
			_putchar(symbol);
			in_length += 2;
	}
	return (in_length);
}

/**
 * switch_char - Helper function that holds the switch statement
 * and calls certain functions depending on the symbol
 * This function deals with characters
 * @arg: va_list passed in from printf.c
 * @symbol: The letter passed in from printf.c
 * @in_length: Variable that holds the number of char printed
 * Return: The number of characters printed
 */
int switch_char(va_list arg, char symbol, int in_length)
{
	switch (symbol)
	{
		case 'c':
			print_char(arg, &in_length);
			break;
		case 's':
			print_string(arg, &in_length, symbol);
			break;
		case 'r':
			print_string(arg, &in_length, symbol);
			break;
		case 'R':
			print_string(arg, &in_length, symbol);
			break;
		case '%':
			_putchar('%');
			in_length++;
			break;
		default:
			_putchar('%');
			_putchar(symbol);
			in_length += 2;
	}
	return (in_length);
}
