#ifndef PRINTF
#define PRINTF
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct printer - conects format specifier with its corresponding function.
 * @flag: format specifier.
 * @function: pointer to @flag especific function.
 */
typedef struct printer
{
	char flag;
	int (*function)(va_list);
} printer_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list arg);
int print_s(va_list arg);
int print_i(va_list arg);
int print_b(va_list arg);
int print_u(va_list arg);
int print_o(va_list arg);
int print_x(va_list arg);
int print_X(va_list arg);
int print_r(va_list arg);
int print_R(va_list arg);

int switch_num(va_list, char, int);
int switch_char(va_list, char, int);
int print_char(va_list, int *);
int print_string(va_list, int *, char);
int print_num(va_list, int *, char);
char *num_converter(unsigned int, unsigned int *);
char *hex_converter(unsigned int, unsigned int *, char);
int count_digits(unsigned int, unsigned int *);
int out_num(char *, int, int *);
char *bnten(int, char, unsigned int *);
void rev_string(char *, int);
char *rot13(char *, int);

#endif
