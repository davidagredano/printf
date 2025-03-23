<h1 align="center">ft_printf</h1>

A custom implementation of the `printf` C function using variadic functions. 

## Introduction 

`printf` is a fundamental C function that produces formatted output according to a format string. It's one of the most commonly used functions in C programming, allowing you to print text and data in various formats.

The function prototype is:

```c
int ft_printf(char const *str, ...);
```

Where:

- `str` is the format string that contains the text to be written and the format specifiers
- `...` indicates that the function accepts a variable number of arguments
- Returns the number of characters written, or a negative value if an error occurs

The format string can contain:

- Regular characters that are copied to the output
- Conversion specifications that start with `%` and end with a conversion specifier
- Escape sequences like `\n` for newline

## Format string syntax

### Conversion specification format

Each conversion specification follows this format:

```c
%[flags][width][.precision]specifier
```

The specification is introduced by `%` and ends with a conversion specifier. In between, you can have (in this order):
1. Zero or more flags
2. An optional minimum field width
3. An optional precision

Arguments are used in the order given, with each conversion specifier requiring the next argument. It's an error if insufficient arguments are provided.

### Supported conversion specifiers
  - `%c` - Single character
  - `%s` - String
  - `%p` - Pointer address
  - `%d` - Signed decimal integer
  - `%i` - Signed integer
  - `%u` - Unsigned decimal integer
  - `%x` - Unsigned hexadecimal integer (lowercase)
  - `%X` - Unsigned hexadecimal integer (uppercase)
  - `%%` - Percent sign

### Format flags
  - `-` - Left alignment
  - `0` - Zero padding
  - `#` - Alternative form (adds 0x prefix for hex)
  - `+` - Always show sign for numbers
  - ` ` (space) - Show space for positive numbers

### Field width and precision
  - `%5d` - Minimum width of 5 characters
  - `%.5d` - Minimum 5 digits for integers
  - `%.5s` - Maximum 5 characters for strings

## Installation

1. Download or clone this repository.
    
    ```bash
    git clone https://github.com/davidagredano/ft_printf.git
    ```
    
2. Move into the project's directory.
    
    ```bash
    cd libft
    ```
    
3. Compile the library. The binary `libftprintf.a` will be created at the root of the directory.
    
    ```bash
    make
    ```

### Other useful commands

| Command | Description |
| --- | --- |
| `make` | Compile the library. |
| `make clean` | Remove the objects files. |
| `make fclean` | Remove the objects files and the library. |
| `make re` | Recompile the library. |


## Usage

### Header

To use the `ft_printf` function, **include its header in your source files**:

```c
#include "path/to/ft_printf.h"
```

### Prototype

Then, you can use the function in your code with the following **prototype**:

```c
int ft_printf(char const *str, ...);
```

### Compilation

When compiling your code, you'll need to **add the required flags to include the library**:

```bash
gcc [option...] infile... -L<path/to/ft_printf/dir> -lftprintf
```

- `-l<library>`
    
    The linker searches for the library named *library*, which is actually a file named `lib<library>.a`. For example, for our **ft_printf** we should use `-lftprintf` since our library is called `libftprintf.a`. [GCC manual](https://gcc.gnu.org/onlinedocs/gcc-2.95.3/gcc_2.html#SEC13)
    
- `-L<dir>`
    
    Add directory *dir* to the list of directories to be searched for `-l`. [GCC manual](https://gcc.gnu.org/onlinedocs/gcc-2.95.3/gcc_2.html#SEC14)
    

## Example usage

### Example directory structure

```
├── ft_printf/
│	├── includes/
│	│	└── ft_printf.h
│	├── libft/
│	├── srcs/
│	├── libftprintf.a
│	└── Makefile
└── your_example_project/
	└── main.c
```

### Content of `/your_example_project/main.c`

```c
#include "../ft_printf/includes/ft_printf.h"

int main()
{
    ft_printf("Hello %s! The answer is %d\n", "World", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Pointer: %p\n", (void *)0x1234);
}
```

### Compilation

```bash
cd your_example_project
gcc -o ft_printf_example main.c -L../ft_printf -lftprintf
```

### Execution

```bash
$> ./ft_printf_example
Hello World! The answer is 42
Hexadecimal: ff
Pointer: 0x1234
$>
```

## **Contact**

Hello! 👋 I'm David, the creator of this project. If you have any questions, suggestions, or just want to chat about software development or anything else, feel free to reach out to me.

My email is [davidagredano@gmail.com](mailto:davidagredano@gmail.com).

Looking forward to hearing from you!
