# Palindrome Integer

## Description

This project focuses on checking whether an unsigned integer is a palindrome.

A number is considered a palindrome when it reads the same forward and backward.

For example:

```text id="nx89zt"
121
12321
12345678987654321
```

are palindromes, while:

```text id="yvq6dd"
112
123456
1234567898654321
```

are not.

The goal is to solve this problem in C without using dynamic memory allocation.

## Problem Statement

Write a function that checks whether a given unsigned integer is a palindrome.

Prototype:

```c id="sqm8yn"
int is_palindrome(unsigned long n);
```

The function must return:

* `1` if `n` is a palindrome
* `0` otherwise

Dynamic memory allocation is not allowed.

## Example

Compilation:

```bash id="wku5fj"
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
```

Execution:

```bash id="q5h3sq"
./palindrome 121
```

Expected output:

```text id="up1sl4"
121 is a palindrome.
```

Another example:

```bash id="lm1d24"
./palindrome 112
```

Expected output:

```text id="h5jdsf"
112 is not a palindrome.
```

## Approach

The function can solve the problem by reversing the digits of the number and comparing the reversed value with the original one.

General logic:

1. Store the original number.
2. Reverse the digits one by one using modulo and division.
3. Compare the reversed number with the original number.
4. Return `1` if they are equal, otherwise return `0`.

Example with `121`:

```text id="pexuvp"
Original number: 121
Reversed number: 121
Result: palindrome
```

Example with `112`:

```text id="sctqlr"
Original number: 112
Reversed number: 211
Result: not a palindrome
```

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="mc3gk4"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* Dynamic memory allocation is not allowed
* All function prototypes must be included in `palindrome.h`
* Header files must be include guarded

## Files

| File                | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| `0-is_palindrome.c` | Contains the implementation of the `is_palindrome` function. |
| `palindrome.h`      | Header file containing the function prototype.               |
| `0-main.c`          | Example test file.                                           |

## Usage

Clone the repository and move into the project directory:

```bash id="tbp4zc"
git clone <repository_url>
cd holbertonschool-interview/palindrome_integer
```

Compile the files:

```bash id="s60sd8"
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
```

Run the program with a number:

```bash id="d22c4r"
./palindrome 12345678987654321
```

Example output:

```text id="spimc5"
12345678987654321 is a palindrome.
```

## Function Prototype

```c id="dqlir8"
int is_palindrome(unsigned long n);
```

## Return Value

The function returns an integer:

* `1` if the number is a palindrome
* `0` if the number is not a palindrome

## Algorithm Complexity

Let `d` be the number of digits in `n`.

* Time complexity: `O(d)`
* Space complexity: `O(1)`

The solution only uses numeric operations and does not allocate additional memory.

## Learning Objectives

This project helps practice:

* numeric manipulation in C
* modulo and division operations
* working with `unsigned long`
* algorithmic reasoning
* edge case handling
* avoiding dynamic memory allocation
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
