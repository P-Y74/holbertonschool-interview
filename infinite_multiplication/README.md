# Infinite Multiplication

## Description

This project focuses on multiplying two positive numbers that can be too large to fit into standard integer types.

Instead of converting the numbers into `int`, `long`, or another numeric type, the program processes them as strings and performs multiplication digit by digit.

This is useful for understanding how large number arithmetic works internally.

## Problem Statement

Write a program that multiplies two positive numbers.

Usage:

```bash id="nn2gcm"
./mul num1 num2
```

Where:

* `num1` and `num2` are positive numbers
* both numbers are passed in base 10
* both arguments must contain only digits

The program must print the result followed by a new line.

If the number of arguments is incorrect, or if one of the arguments contains a non-digit character, the program must print:

```text id="76j9dv"
Error
```

and exit with status code `98`.

## Example

Compilation:

```bash id="b3jsqk"
gcc -Wall -pedantic -Werror -Wextra 0-mul.c _putchar.c -o mul
```

Execution:

```bash id="ky3crr"
./mul 10 98
```

Output:

```text id="o00cbm"
980
```

Example with very large numbers:

```bash id="og2u2s"
./mul 123456789987654321 987654321123456789
```

The program must correctly compute the result without relying on built-in integer limits.

## Approach

The program performs multiplication manually, using the same logic as long multiplication on paper.

General steps:

1. Validate the number of command-line arguments.
2. Check that both input strings contain only digits.
3. Allocate enough memory to store the result.
4. Multiply each digit of the first number by each digit of the second number.
5. Store intermediate results in an integer array.
6. Handle carry values.
7. Skip leading zeros when printing the final result.
8. Print the result using `_putchar`.

The maximum size of the result is at most:

```text id="ihjlmd"
length(num1) + length(num2)
```

This allows the program to allocate enough memory for the multiplication result.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="k7fw1d"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* The only allowed C standard library functions are:

```text id="zae725"
malloc, free, exit
```

* Functions such as `printf`, `puts`, `calloc`, and `realloc` are forbidden
* `_putchar` is allowed
* Function prototypes must be included in `holberton.h`
* The program must exit with status code `98` on error
* More than 5 functions are allowed for this task

## Files

| File          | Description                                           |
| ------------- | ----------------------------------------------------- |
| `0-mul.c`     | Program that multiplies two positive numbers.         |
| `holberton.h` | Header file containing function prototypes.           |
| `_putchar.c`  | Helper function used for output during local testing. |

## Usage

Clone the repository and move into the project directory:

```bash id="6mziic"
git clone <repository_url>
cd holbertonschool-interview/infinite_multiplication
```

Compile the program:

```bash id="0mn4mx"
gcc -Wall -Werror -Wextra -pedantic 0-mul.c _putchar.c -o mul
```

Run it with two positive numbers:

```bash id="q1v0ho"
./mul 235 98
```

Output:

```text id="d2mbaj"
23030
```

Invalid usage example:

```bash id="bwo0fr"
./mul 123 abc
```

Output:

```text id="lzlj44"
Error
```

## Program Behavior

| Case                        | Expected behavior                       |
| --------------------------- | --------------------------------------- |
| Correct number of arguments | Multiply both numbers                   |
| Missing argument            | Print `Error` and exit with status `98` |
| Too many arguments          | Print `Error` and exit with status `98` |
| Non-digit character         | Print `Error` and exit with status `98` |
| Very large valid numbers    | Print the correct multiplication result |

## Algorithm Complexity

Let:

* `n` be the length of `num1`
* `m` be the length of `num2`

The multiplication compares each digit of one number with each digit of the other.

* Time complexity: `O(n * m)`
* Space complexity: `O(n + m)`

The result array size depends on the maximum possible number of digits in the final product.

## Learning Objectives

This project helps practice:

* command-line argument handling in C
* string validation
* digit-by-digit arithmetic
* manual multiplication algorithm
* dynamic memory allocation
* carry management
* output without `printf`
* error handling with exit codes
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
