# Merge Sort

## Description

This project focuses on sorting an array of integers using the Merge Sort algorithm.

Merge Sort is a divide-and-conquer sorting algorithm. It recursively divides an array into smaller sub-arrays, sorts them, and then merges them back together in ascending order.

This project uses the top-down Merge Sort approach.

## Problem Statement

Write a function that sorts an array of integers in ascending order using the Merge Sort algorithm.

Prototype:

```c id="0rys8q"
void merge_sort(int *array, size_t size);
```

The function must:

* sort the array in ascending order
* use the top-down Merge Sort algorithm
* sort the left sub-array before the right sub-array
* print the arrays during each merge step
* do nothing if the array size is less than `2`

When dividing an array into two sub-arrays, the left array size must always be less than or equal to the right array size.

Example:

```text id="mb2dyz"
{1, 2, 3, 4, 5}
```

must be divided into:

```text id="f7aqoo"
{1, 2}
{3, 4, 5}
```

## Merge Sort Concept

Merge Sort works in two main phases:

1. **Divide**

   The array is recursively split into smaller sub-arrays until each part contains one element.

2. **Merge**

   The sub-arrays are merged back together in sorted order.

Because each merge step combines already sorted parts, the final result is a fully sorted array.

## Example

Initial array:

```text id="b47jsr"
19, 48, 99, 71, 13, 52, 96, 73, 86, 7
```

After running Merge Sort:

```text id="2cbx3v"
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

Compilation:

```bash id="hrdsgw"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
```

Execution:

```bash id="b6tw3u"
./merge
```

Example output during sorting:

```text id="2nbq11"
Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 99
[right]: 13, 71
[Done]: 13, 71, 99
```

Final output:

```text id="e8y3sg"
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Approach

The function implements a top-down Merge Sort.

The general logic is:

1. Check if the array is valid and has at least two elements.
2. Allocate a temporary buffer used during the merge process.
3. Recursively split the array into left and right sub-arrays.
4. Sort the left sub-array first.
5. Sort the right sub-array.
6. Merge both sorted parts into the original array.
7. Print the left part, the right part, and the merged result.

A temporary buffer is used to merge values correctly without overwriting data that still needs to be compared.

## Output Format

During each merge step, the function prints:

```text id="1wqj67"
Merging...
[left]: <left array>
[right]: <right array>
[Done]: <merged array>
```

This output helps visualize how the array is progressively divided and rebuilt in sorted order.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="jm7l2p"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* Standard library usage is forbidden unless specified
* `printf` is allowed
* `malloc` and `free` are allowed only once
* All function prototypes must be included in `sort.h`
* Header files must be include guarded
* Arrays with less than 2 elements do not need to be sorted

## Files

| File             | Description                                              |
| ---------------- | -------------------------------------------------------- |
| `0-merge_sort.c` | Contains the implementation of the Merge Sort algorithm. |
| `sort.h`         | Header file containing function prototypes.              |
| `0-O`            | Contains the Big O time complexities of Merge Sort.      |
| `print_array.c`  | Helper function used to print arrays.                    |
| `0-main.c`       | Example test file.                                       |

## Function Prototype

```c id="27k3y5"
void merge_sort(int *array, size_t size);
```

The `print_array` function must also be declared in `sort.h`:

```c id="jio1ii"
void print_array(const int *array, size_t size);
```

## Big O Notation

The `0-O` file contains the time complexity of Merge Sort:

```text id="20ifn3"
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

```bash id="l6y7ez"
git clone <repository_url>
cd holbertonschool-interview/merge_sort
```

Compile the files:

```bash id="6ptdo6"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
```

Run the program:

```bash id="ii9jpb"
./merge
```

## Algorithm Complexity

Let `n` be the number of elements in the array.

* Best case: `O(nlog(n))`
* Average case: `O(nlog(n))`
* Worst case: `O(nlog(n))`
* Space complexity: `O(n)`

Merge Sort requires additional temporary storage to merge sub-arrays.

## Learning Objectives

This project helps practice:

* sorting algorithms
* divide-and-conquer logic
* recursive algorithms
* array manipulation in C
* merge operations
* memory allocation management
* algorithm complexity analysis
* strict C compilation requirements
* Betty-compliant C code

## Author

Pierre-Yves
