#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "main.h"

int _putchar(char c);
int _printf(const char *format, ...);
void print_char(va_list arg);
void print_string(va_list arg);
void print_percent(va_list arg);
void print_invalid(char c);

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints output according to a format.
 * @format: character string containing zero or more directives.
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *p;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
	{
		return (-1);
	}

	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '\0')
				return (-1);
			else if (*p == 'c')
				print_char(arg, &count);
			else if (*p == 's')
				print_string(arg, &count);
			else if (*p == '%')
				print_percent(arg, &count);
			else
				print_invalid(*p, &count);
		}
		else
		{
			_putchar(*p);
			count++;
		}
	}

	va_end(arg);

	return (count);
}

/**
 * print_char - prints a single character.
 * @arg: list of arguments
 * @count: pointer to the count of printed characters
 */
void print_char(va_list arg, int *count)
{
	char c = va_arg(arg, int);
	_putchar(c);
	(*count)++;
}

/**
 * print_string - prints a string.
 * @arg: list of arguments
 * @count: pointer to the count of printed characters
 */
void print_string(va_list arg, int *count)
{
	char *str = va_arg(arg, char*);
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		(*count)++;
	}
}

/**
 * print_percent - prints a percent sign.
 * @arg: list of arguments
 * @count: pointer to the count of printed characters
 */
void print_percent(va_list arg, int *count)
{
	_putchar('%');
	(*count)++;
}

/**
 * print_invalid - prints an invalid format specifier.
 * @c: invalid format specifier
 * @count: pointer to the count of printed characters
 */
void print_invalid(char c, int *count)
{
	_putchar('%');
	_putchar(c);
	(*count) += 2;
}
