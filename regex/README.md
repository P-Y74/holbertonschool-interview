# RegEx

## Description

This project focuses on implementing a simple regular expression matcher in C.

The goal is to check whether a given pattern matches a given string using only two special regex characters:

* `.`
* `*`

This exercise helps practice recursion, string comparison, pointer manipulation, and pattern-matching logic.

## Problem Statement

Write a function that checks whether a given pattern matches a given string.

Prototype:

```c
int regex_match(char const *str, char const *pattern);
```

Where:

* `str` is the string to scan
* `pattern` is the regular expression pattern

The function must return:

* `1` if the pattern matches the string
* `0` if the pattern does not match the string

The match must apply to the whole string.

## Supported Pattern Rules

The regular expression engine supports two special characters.

### Dot `.`

The dot matches any single character.

Example:

```text
.olberton
```

matches:

```text
Holberton
```

because `.` replaces the first character `H`.

### Star `*`

The star matches zero or more occurrences of the preceding character.

Example:

```text
H*
```

matches:

```text
HHHH
```

because `*` allows the character `H` to appear multiple times.

It can also match zero occurrences.

Example:

```text
Z*H.*
```

matches:

```text
Holberton
```

because `Z*` can match nothing.

## Examples

Compilation:

```bash
gcc -Wall -Wextra -Werror -pedantic main.c regex.c
```

Execution:

```bash
./a.out
```

Example output:

```text
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
```

## Approach

The function can be solved recursively by comparing the current character of the string with the current character of the pattern.

The general logic is:

1. If both the string and pattern reach the end, return `1`.
2. Check whether the current characters match:

   * same character
   * or pattern character is `.`
3. If the next pattern character is `*`, handle two possibilities:

   * `*` matches zero occurrences, so move past the character and `*` in the pattern
   * `*` matches one or more occurrences, so move forward in the string while keeping the same pattern
4. If there is no `*`, move forward in both the string and pattern only if the current characters match.
5. Return `0` when no valid match is possible.

This recursive branching allows the function to handle patterns such as:

```text
.*
Z*H.*
H*
```

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
* No more than 5 functions per file
* Example `main.c` files are only for testing
* All function prototypes must be included in `regex.h`
* Header files must be include guarded

## Files

| File      | Description                                                |
| --------- | ---------------------------------------------------------- |
| `regex.c` | Contains the implementation of the `regex_match` function. |
| `regex.h` | Header file containing the function prototype.             |
| `main.c`  | Example test file.                                         |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/regex
```

Compile the files:

```bash
gcc -Wall -Wextra -Werror -pedantic main.c regex.c
```

Run the program:

```bash
./a.out
```

## Function Prototype

```c
int regex_match(char const *str, char const *pattern);
```

## Return Value

The function returns an integer:

* `1` if the pattern matches the string
* `0` if the pattern does not match the string

## Algorithm Complexity

Let:

* `n` be the length of `str`
* `m` be the length of `pattern`

Because `*` can create recursive branching, the worst-case time complexity can become exponential depending on the pattern.

* Best case: `O(n)`
* Worst case: `O(2^n)` in complex recursive matching cases
* Space complexity: `O(n + m)` due to recursive calls

## Learning Objectives

This project helps practice:

* recursive algorithms
* simple regular expression matching
* string traversal in C
* pointer manipulation
* handling special pattern characters
* branching logic with `*`
* base case management
* strict C compilation requirements
* Betty-compliant C code

## Author

Pierre-Yves
