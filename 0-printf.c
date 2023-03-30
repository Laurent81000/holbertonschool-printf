#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
<<<<<<< HEAD
#include "main.h"
=======
>>>>>>> 70690b08afafa3efe7dbf9b288f229e8a9727144

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
<<<<<<< HEAD
	return (write(1, &c, 1));
=======
	return write(1, &c, 1);
>>>>>>> 70690b08afafa3efe7dbf9b288f229e8a9727144
}

/**
 * _printf - prints output according to a format.
 * @format: character string containing zero or more directives.
 * Return: the number of characters printed (excluding the null byte
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
=======
	va_list args;
>>>>>>> 70690b08afafa3efe7dbf9b288f229e8a9727144
	int count = 0;

<<<<<<< HEAD
	va_start(arg, format);
	for (p = format; *p != '\0'; p++)
=======
	va_start(args, format);

	while (*format)
>>>>>>> 70690b08afafa3efe7dbf9b288f229e8a9727144
	{
		if (*format == '%')
		{
<<<<<<< HEAD
			p++;
			if (*p == '\0')
				return (-1);
			else if (*p == 'c')
=======
			format++;

			/* Print a single character */
			if (*format == 'c')
>>>>>>> 70690b08afafa3efe7dbf9b288f229e8a9727144
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
<<<<<<< HEAD
	va_end(arg);
=======

	va_end(args);
>>>>>>> 70690b08afafa3efe7dbf9b288f229e8a9727144

	return (count);
}


