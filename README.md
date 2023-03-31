Project Title

_printf function implementation
Description

This project is an implementation of the C standard library function printf. The printf function allows printing formatted output to the console. This implementation includes the following format specifiers:

    %c: for printing characters
    %s: for printing strings
    %d, %i: for printing signed integers
    %%: for printing the % symbol

Compilation command

To compile the project, use the following command:

bash

gcc -Wall -Werror -Wextra -pedantic *.c -o printf

Requirements

    Ubuntu 20.04 LTS
    GCC compiler
    git

Examples

c

#include "holberton.h"

int main(void)
{
        int len;

        len = _printf("Hello %s, have a %d%c day", "world", 10, '!');
        _printf("\nLength: %d\n", len);

        return (0);
}

Output:

css

Hello world, have a 10! day
Length: 28

Man page

To access the manual page for this implementation of printf, run the following command:

bash

man ./man_3_printf

Testing

Testing was done using the CUnit unit testing framework. The test suite can be found in the tests directory, and can be compiled and run with the following commands:

bash

gcc -Wall -Werror -Wextra -pedantic -I../ -I./../tests -L../ -lcunit -o test_printf test_printf.c ../libprintf.a
./test_printf

Memory leaks were checked using the Valgrind tool:

bash

valgrind --leak-check=full ./test_printf

Flowchart
