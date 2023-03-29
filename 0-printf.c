#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - prints output according to a format.
 * @format: character string containing zero or more directives.
 * Return: the number of characters printed (excluding the null byte 
 * used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	int i = 0;
	va_list args;
	char c;
	char *s;
/** 
 * Second step: we create a loop to count
 * the number of characters in the format string 
 */
	while ((c = format[i++]))
	{
/**
 * Third step: we search if the character is different from '%'.
 * If c != '%' we print the characters
 * if c = '%' we have to manage the printf format directive
 */
		if (c != '%')
		{
			_putchar(c);
			counter++;
		}
		else
		{

/**
 * Fourth step: A switch will be used to clarify the code
 * of our 3 cases: c, s and %.
 */
			switch (format[i++])
			{
/**
 * Fifth step: Case for characters
 * Using va_arg to retrieve the sequence of arguments (...)
 * A single character displayed one by one, then counted
 */
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					counter++;
					break;
			}
/**
 * Sixth step: Case for the string
 * va_arg + 
 * loop to display and count each character that makes up a string
 */
			case 's':
			s = va_arg(args, char*);
			while (*s)
			{
				_putchar(*s++);
				counter++;
			}
			break;
/**
 * Seventh step: Case for the '%' formatting symbol
 * va_arg + 
 * display and count the '%'
 */ 
			case '%':
			_putchar('%');
			counter++;
			break;
/* switch syntax */
			default:
/**
 * For "%c" and "%s" we add +2 to not display them
 * For '%' we remove -1 to +2 to not display it
 */ 
			_putchar('%');
			_putchar(format[i - 1]);
			counter += 2;
			break;
		}
	}
}
va_end(args);
/** 
 * First step: the prototype returns the number of printed 
 *characters
 * we do this with a counter 
 */
return (counter);
}


