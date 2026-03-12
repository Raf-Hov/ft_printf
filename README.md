*This project has been created as part of the 42 curriculum by rafhovha*

# ft_printf

## Description
The goal of this project is to recreate the behavior of the standard C library function `printf`. 
`ft_printf` is a custom implementation that formats and prints data to the standard output. This project serves as a deep dive into variadic functions in C, teaching how to handle an unknown number of arguments of varying types. 

The function handles the following conversion specifiers:
* `%c` Prints a single character.
* `%s` Prints a string (as defined by the common C convention).
* `%p` The `void *` pointer argument is printed in hexadecimal format.
* `%d` Prints a decimal (base 10) number.
* `%i` Prints an integer in base 10.
* `%u` Prints an unsigned decimal (base 10) number.
* `%x` Prints a number in hexadecimal (base 16) lowercase format.
* `%X` Prints a number in hexadecimal (base 16) uppercase format.
* `%%` Prints a percent sign.

## Instructions

### Compilation & Installation

To compile the project and generate the static library, clone the repository and run `make`:

```bash
git clone [your-repo-link]
cd [project-directory]
make
```
This will generate the static library file libftprintf.a.

Execution
Since this is a library, it is not executed directly. To use ft_printf in your own projects:

Include the header in your C files:
```
#include "ft_printf.h"
```
Compile your program with the library:

```
cc -Wall -Wextra -Werror your_main.c libftprintf.a -o your_program
./your_program
```
## Resources

### References

``man 3 printf`` - The definitive manual for the standard printf behavior.

``man 3 stdarg`` - Documentation for handling variadic arguments (va_start, va_arg, va_copy, va_end).

``Secrets of printf`` - Insight into how printf actually works under the hood.
