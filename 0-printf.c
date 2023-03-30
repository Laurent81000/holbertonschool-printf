#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - prints output according to a format.
 * @format: character string containing zero or more directives.
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			/* Print a single character */
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				count += _putchar(c);
			}
			/* Print a string */
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);
				while (*s)
				{
					count += _putchar(*s);
					s++;
				}
			}
			/* Print a percent sign */
			else if (*format == '%')
			{
				count += _putchar('%');
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}


