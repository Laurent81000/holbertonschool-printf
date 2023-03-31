![Logo Holberton](https://user-images.githubusercontent.com/124588032/229158100-bd428e63-72ec-4cad-8048-7c9369907123.jpg)

# C - printf

## Project Title

_printf function implementation

## Description

This project is an implementation of the C standard library function printf. The printf function allows printing formatted output to the console. This implementation includes the following format specifiers:

    %c: for printing characters
    %s: for printing strings
    %d, %i: for printing signed integers
    %%: for printing the % symbol

## Compilation command

To compile the project, use the following command:

gcc -Wall -Werror -Wextra -pedantic *.c -o printf

## Requirements

    Ubuntu 20.04 LTS
    GCC compiler
    git

## Examples


#include "holberton.h"

int main(void)
{
        int len;

        len = _printf("Hello %s, have a %d%c day", "world", 10, '!');
        _printf("\nLength: %d\n", len);

        return (0);
}

## Output:

Hello world, have a 10! day
Length: 28

## Man page

To access the manual page for this implementation of printf, run the following command:

man ./man_3_printf

## Testing

Testing was done using the CUnit unit testing framework. The test suite can be found in the tests directory, and can be compiled and run with the following commands:

gcc -Wall -Werror -Wextra -pedantic -I../ -I./../tests -L../ -lcunit -o test_printf test_printf.c ../libprintf.a
./test_printf

## Flowchart

![Flowchart](https://user-images.githubusercontent.com/124588032/229160104-2d9eca2f-b02c-4ecd-8834-5aec738e464c.png)

## Authors
Alexis Grandjean
Laurent Lavigne
