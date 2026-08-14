# Wild Compare

## Description

This project focuses on comparing two strings where one of them can contain a wildcard character.

The wildcard character `*` can match any string, including an empty string.

The goal is to implement this comparison in C using recursion, without loops and without using the standard library.

## Problem Statement

Write a function that compares two strings and returns whether they can be considered identical.

Prototype:

```c
int wildcmp(char *s1, char *s2);
```

Where:

* `s1` is the original string
* `s2` is the string that may contain the wildcard character `*`

The function must return:

* `1` if the strings can be considered identical
* `0` otherwise

## Wildcard Rule

The special character `*` in `s2` can replace:

* any sequence of characters
* a single character
* an empty string

Examples:

```text
s1 = "main.c"
s2 = "*.c"
```

Result:

```text
1
```

Because `*` can replace `main`.

Another example:

```text
s1 = "main.c"
s2 = "*"
```

Result:

```text
1
```

Because `*` can replace the whole string.

## Examples

Compilation:

```bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
```

Execution:

```bash
./0-wildcmp
```

Example tests:

```c
wildcmp("main.c", "*.c");
wildcmp("main.c", "m*a*i*n*.*c*");
wildcmp("main.c", "main.c");
wildcmp("main.c", "m*c");
wildcmp("main.c", "ma********************************c");
wildcmp("main.c", "*");
wildcmp("main.c", "***");
wildcmp("main.c", "m.*c");
wildcmp("main.c", "**.*c");
wildcmp("main-main.c", "ma*in.c");
wildcmp("main", "main*d");
wildcmp("abc", "*b");
```

Expected output:

```text
1
1
1
1
1
1
1
0
1
1
0
0
```

## Approach

The function is solved recursively.

At each step, the function compares the current characters of `s1` and `s2`.

General logic:

1. If both strings reach the end at the same time, return `1`.
2. If the current characters are equal, move forward in both strings.
3. If the current character in `s2` is `*`, recursively try two possibilities:

   * `*` matches an empty string, so move forward in `s2`
   * `*` matches one or more characters, so move forward in `s1`
4. If the characters are different and `s2` is not `*`, return `0`.

This recursive branching allows the function to test all valid meanings of the wildcard.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No static variables allowed
* No more than 5 functions per file
* The standard library is not allowed
* Loops of any kind are not allowed
* All function prototypes must be included in `holberton.h`
* Header files must be include guarded

## Files

| File          | Description                                            |
| ------------- | ------------------------------------------------------ |
| `0-wildcmp.c` | Contains the implementation of the `wildcmp` function. |
| `holberton.h` | Header file containing the function prototype.         |
| `0-main.c`    | Example test file.                                     |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/wild_cmp
```

Compile the files:

```bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
```

Run the program:

```bash
./0-wildcmp
```

## Function Prototype

```c
int wildcmp(char *s1, char *s2);
```

## Return Value

The function returns an integer:

* `1` if the strings match
* `0` if the strings do not match

## Algorithm Complexity

Let:

* `n` be the length of `s1`
* `m` be the length of `s2`

Because the wildcard `*` can create multiple recursive branches, the worst-case time complexity can be exponential depending on the number and position of wildcard characters.

* Best case: `O(n)`
* Worst case: `O(2^n)` in complex wildcard cases
* Space complexity: `O(n + m)` due to recursive calls

## Learning Objectives

This project helps practice:

* recursive string comparison
* wildcard matching logic
* pointer manipulation in C
* base case handling
* branching recursion
* solving problems without loops
* avoiding standard library functions
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
