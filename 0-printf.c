#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
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
			{
				return (-1);
			}
			else if (*p == 'c')
			{
				char c = va_arg(arg, int);
				_putchar(c);
				count++;
			}
			else if (*p == 's')
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
					count++;
				}
			}
			else if (*p == 'd' || *p == 'i')
			{
				long int num = va_arg(arg, int);


				int div = 1;
				if (num < 0)
				{
					_putchar('-');
					count++;
					num = -num;
				}
				while (num / div > 9)
				{
					div *= 10;
				}
				do {
					_putchar(num / div + '0');
					count++;
					num %= div;
					div /= 10;
				} while (div > 0);
			}
			else if (*p == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(*p);
				count += 2;
			}
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
