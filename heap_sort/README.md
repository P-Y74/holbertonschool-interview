# Heap Sort

## Description

This project focuses on sorting an array of integers using the Heap Sort algorithm.

Heap Sort is a comparison-based sorting algorithm that uses a binary heap structure.
In this project, the array must be sorted in ascending order using the sift-down approach.

The function prints the array every time two elements are swapped.

## Problem Statement

Write a function that sorts an array of integers in ascending order using the Heap Sort algorithm.

Prototype:

```c
void heap_sort(int *array, size_t size);
```

The function must:

* sort the array in ascending order
* use the sift-down Heap Sort algorithm
* print the array after each swap
* do nothing if the array size is less than `2`

## Heap Sort Concept

Heap Sort works in two main phases:

1. **Build a max heap**

   The array is reorganized so that the largest value is stored at the root of the heap.

2. **Extract elements one by one**

   The root element is swapped with the last element of the heap.
   The heap size is then reduced, and the remaining heap is restored using sift-down.

Because a max heap always keeps the largest value at the root, moving the root to the end of the array places each element in its final sorted position.

## Example

Initial array:

```text
19, 48, 99, 71, 13, 52, 96, 73, 86, 7
```

After running Heap Sort, the final sorted array is:

```text
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

Compilation:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

Execution:

```bash
./0-heap
```

## Approach

The function uses the sift-down version of Heap Sort.

The general logic is:

1. Build a max heap from the input array.
2. Swap the root of the heap with the last element.
3. Reduce the heap size.
4. Restore the max heap property using sift-down.
5. Repeat until the array is sorted.

Each swap is followed by a call to `print_array`.

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
* Standard library usage is not allowed unless specified
* All function prototypes must be included in `sort.h`
* Header files must be include guarded
* Arrays with less than 2 elements do not need to be sorted

## Files

| File            | Description                                             |
| --------------- | ------------------------------------------------------- |
| `0-heap_sort.c` | Contains the implementation of the Heap Sort algorithm. |
| `sort.h`        | Header file containing function prototypes.             |
| `0-O`           | Contains the Big O time complexities of Heap Sort.      |
| `print_array.c` | Helper function used to print the array.                |
| `0-main.c`      | Example test file.                                      |

## Function Prototype

```c
void heap_sort(int *array, size_t size);
```

The `print_array` function must also be declared in `sort.h`:

```c
void print_array(const int *array, size_t size);
```

## Big O Notation

The `0-O` file contains the time complexity of Heap Sort:

```text
O(nlog(n))
O(nlog(n))
O(nlog(n))
```

These correspond to:

1. best case
2. average case
3. worst case

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/heap_sort
```

Compile the files:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

Run the program:

```bash
./0-heap
```

Example final output:

```text
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Algorithm Complexity

Let `n` be the number of elements in the array.

* Best case: `O(nlog(n))`
* Average case: `O(nlog(n))`
* Worst case: `O(nlog(n))`
* Space complexity: `O(1)`

Heap Sort sorts the array in place and does not require additional dynamic memory.

## Learning Objectives

This project helps practice:

* sorting algorithms
* binary heap structure
* max heap construction
* sift-down operation
* in-place array manipulation
* algorithm complexity analysis
* strict C compilation requirements
* Betty-compliant C code

## Author

Pierre-Yves
