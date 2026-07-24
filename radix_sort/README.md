# Radix Sort

## Description

This project focuses on sorting an array of non-negative integers using the Radix Sort algorithm.

Radix Sort is a non-comparison sorting algorithm. Instead of comparing values directly, it sorts numbers digit by digit, starting from the least significant digit.

This project uses the LSD Radix Sort approach, which means the sorting starts from the units digit, then moves to tens, hundreds, and so on.

## Problem Statement

Write a function that sorts an array of integers in ascending order using the Radix Sort algorithm.

Prototype:

```c id="v22p89"
void radix_sort(int *array, size_t size);
```

The function must:

* sort the array in ascending order
* implement the LSD Radix Sort algorithm
* assume the array contains only numbers greater than or equal to `0`
* print the array each time the significant digit increases
* do nothing if the array size is less than `2`

## Radix Sort Concept

Radix Sort processes numbers by digits.

For example, with this array:

```text id="zb1uy4"
19, 48, 99, 71, 13, 52, 96, 73, 86, 7
```

The algorithm first sorts by the units digit:

```text id="k67uui"
71, 52, 13, 73, 96, 86, 7, 48, 19, 99
```

Then it sorts by the tens digit:

```text id="rlwjip"
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

After processing all significant digits, the array is sorted.

## LSD Radix Sort

LSD stands for **Least Significant Digit**.

The algorithm starts with the rightmost digit and moves left:

```text id="lwlkwb"
units -> tens -> hundreds -> thousands -> ...
```

For each digit position, the array is sorted while preserving the order of elements with the same digit.
This stable sorting behavior is what allows Radix Sort to correctly sort the full numbers after all digit positions have been processed.

## Example

Initial array:

```text id="w0bvru"
19, 48, 99, 71, 13, 52, 96, 73, 86, 7
```

Compilation:

```bash id="nt3o8s"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

Execution:

```bash id="34aadk"
./radix
```

Example output:

```text id="t6dwzc"
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Approach

The function uses LSD Radix Sort with a stable counting sort step for each digit.

The general logic is:

1. Check if the array is valid and has at least two elements.
2. Find the largest number in the array.
3. Start with the units digit.
4. Sort the array according to the current digit.
5. Print the array.
6. Move to the next significant digit.
7. Repeat until all digits of the largest number have been processed.

A temporary array is used during each pass to store values in the correct order before copying them back into the original array.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="4xnvr7"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* Standard library usage is forbidden unless specified
* `malloc` and `free` are allowed for this task
* All function prototypes must be included in `sort.h`
* Header files must be include guarded
* Arrays with less than 2 elements do not need to be sorted

## Files

| File             | Description                                              |
| ---------------- | -------------------------------------------------------- |
| `0-radix_sort.c` | Contains the implementation of the Radix Sort algorithm. |
| `sort.h`         | Header file containing function prototypes.              |
| `print_array.c`  | Helper function used to print the array.                 |
| `0-main.c`       | Example test file.                                       |

## Function Prototype

```c id="pxgp4n"
void radix_sort(int *array, size_t size);
```

The `print_array` function must also be declared in `sort.h`:

```c id="n3m0ni"
void print_array(const int *array, size_t size);
```

## Usage

Clone the repository and move into the project directory:

```bash id="mp7y2l"
git clone <repository_url>
cd holbertonschool-interview/radix_sort
```

Compile the files:

```bash id="ra1jrw"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

Run the program:

```bash id="evrfsw"
./radix
```

## Algorithm Complexity

Let:

* `n` be the number of elements in the array
* `d` be the number of digits in the largest number
* `b` be the base used for sorting, usually `10`

The complexity is:

* Time complexity: `O(d * (n + b))`
* Space complexity: `O(n + b)`

With base `10`, this is often simplified to:

```text id="x5h2v7"
O(d * n)
```

## Learning Objectives

This project helps practice:

* sorting algorithms
* non-comparison sorting
* LSD Radix Sort
* stable digit-based sorting
* counting sort logic
* array manipulation in C
* dynamic memory allocation
* algorithm complexity reasoning
* strict C compilation requirements
* Betty-compliant C code

## Author

Pierre-Yves
