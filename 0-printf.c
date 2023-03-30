#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "_putchar"
#include "main.h"

/**
 * _printf - prints output according to a format.
 * @format: character string containing zero or more directives.
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    const char *p;
    va_list arg;

    va_start(arg, format);
    for (p = format; *p != '\0'; p++)
    {
        if (*p == '%')
        {
            p++;
            if (*p == '\0')
                return (-1);
            else if (*p == 'c')
            {
                char c = va_arg(arg, int);
                _putchar(c);
                count++;
            }
            else if (*p == 's')
            {
                char *str = va_arg(arg, char*);
                while (*str != '\0')
                {
                    _putchar(*str);
                    str++;
                    count++;
                }
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
