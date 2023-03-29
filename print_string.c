#include "main.h"

/**
 *rev_string - prints the reversed string
 *
 * @s: string that is passed
 * @length: length of the string
 *
 * Return: No return type
 */
void rev_string(char *s, int length)
{
	int j;
	char temp;

	length--;

	for (j = 0; j <= length; j++, length--)
	{
		temp = s[j];
		s[j] = s[length];
		s[length] = temp;
	}
}
/**
 *rot13 - pushes the character by 13 untis forward
 *
 * @str: string that is passed
 * @length: lenght of the string that is passed
 *
 * Return: pointer to the string modified
 */
char *rot13(char *str, int length)
{
	char regALPHA[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char altALPHA[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	for (i = 0; i < length; i++)
	{
		for (j = 0; regALPHA[j]; j++)
		{
			if (str[i] == regALPHA[j])
			{
				str[i] = altALPHA[j];
				break;
			}
		}
	}
	return (str);
}

/**
 * print_string - Helper function that prints a string
 * @arg: va_list passed in from printf.c
 * @in_length: Variable that holds the number of char printed
 * @ltr: the identifier that was called/used
 * Return: The number of characters printed in this function
 */
int print_string(va_list arg, int *in_length, char ltr)
{
	int i, length = 0;
	char *string = NULL;
	char *ptr = NULL;

	string = va_arg(arg, char *);

	if (string == NULL)
	{
		write(1, "(null)", 6);
		return (*in_length + 6);
	}

	for (i = 0; string[i]; i++)
		length++;

	ptr = malloc(length * sizeof(char));
	if (ptr == NULL)
		return (-1);
	for (i = 0; i < length; i++)
		ptr[i] = string[i];

	if (ltr == 'r')
		rev_string(ptr, length);
	else if (ltr == 'R')
		rot13(ptr, length);

	for (i = 0; ptr[i]; i++)
	{
		_putchar(ptr[i]);
	}

	*in_length += i;
	free(ptr);
	return (*in_length);
}
