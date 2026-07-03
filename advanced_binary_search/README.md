# Advanced Binary Search

## Description

This project focuses on implementing an advanced version of the binary search algorithm.

Unlike a basic binary search, this version must return the index of the **first occurrence** of a value when the value appears multiple times in the sorted array.

The function must use recursion and print each subarray being searched.

## Problem Statement

Write a function that searches for a value in a sorted array of integers.

Prototype:

```c id="4agqii"
int advanced_binary(int *array, size_t size, int value);
```

Where:

* `array` is a pointer to the first element of the array
* `size` is the number of elements in the array
* `value` is the value to search for

The function must return:

* the index of the first occurrence of `value`
* `-1` if the value is not found
* `-1` if the array is `NULL`

## Advanced Binary Search Concept

A regular binary search can find a matching value, but it does not always return the first occurrence when duplicates exist.

For example, in this array:

```text id="fz8bn9"
0, 1, 2, 5, 5, 6, 6, 7, 8, 9
```

Searching for `5` should return:

```text id="1f73bw"
3
```

because the first `5` is located at index `3`.

The goal of this project is to keep the efficiency of binary search while making sure the leftmost matching value is returned.

## Example

Compilation:

```bash id="f2om9g"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary
```

Execution:

```bash id="zf0nxy"
./0-advanced_binary
```

Example output:

```text id="sroms5"
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

## Approach

The function uses recursive binary search.

At each step:

1. Print the current array or subarray being searched.
2. Find the middle index.
3. If the middle value is greater than or equal to the target, continue searching on the left side.
4. If the middle value is smaller than the target, continue searching on the right side.
5. Return the first index where the target value appears.

The key difference from a standard binary search is that the search continues toward the left side when a matching value is found, to make sure the first occurrence is returned.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="9cez2y"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* Only the `printf` function from the standard library is allowed
* Calls to functions such as `malloc`, `strdup`, or similar are forbidden
* Recursion must be used
* Only one loop is allowed, and it must be used to print the array
* All function prototypes must be included in `search_algos.h`
* Header files must be include guarded

## Files

| File                  | Description                                                          |
| --------------------- | -------------------------------------------------------------------- |
| `0-advanced_binary.c` | Contains the implementation of the advanced binary search algorithm. |
| `search_algos.h`      | Header file containing the function prototype.                       |
| `0-main.c`            | Example test file.                                                   |

## Usage

Clone the repository and move into the project directory:

```bash id="f8tg5s"
git clone <repository_url>
cd holbertonschool-interview/advanced_binary_search
```

Compile the files:

```bash id="r3by81"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o 0-advanced_binary
```

Run the program:

```bash id="t02x6u"
./0-advanced_binary
```

## Function Prototype

```c id="i5kznr"
int advanced_binary(int *array, size_t size, int value);
```

## Return Value

The function returns an integer:

* index of the first occurrence of `value`
* `-1` if `value` is not present
* `-1` if `array` is `NULL`

## Algorithm Complexity

Let `n` be the number of elements in the array.

* Time complexity: `O(log(n))`
* Space complexity: `O(log(n))`

The space complexity comes from the recursive call stack.

## Learning Objectives

This project helps practice:

* binary search
* recursive algorithms
* searching in sorted arrays
* handling duplicate values
* returning the first occurrence of a value
* formatted output during algorithm execution
* strict C compilation requirements
* Betty-compliant C code

## Author

Pierre-Yves
