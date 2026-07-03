# Linear Search in Skip List

## Description

This project focuses on searching for a value in a sorted skip list.

A skip list is a linked list with an additional express lane that allows the search to skip over several nodes at a time before performing a regular linear search in a smaller range.

This exercise helps optimize searching in a linked list while still working with pointer-based data structures in C.

## Problem Statement

Write a function that searches for a value in a sorted skip list of integers.

Prototype:

```c id="nrd3d8"
skiplist_t *linear_skip(skiplist_t *list, int value);
```

Where:

* `list` is a pointer to the head of the skip list
* `value` is the value to search for

The function must return:

* a pointer to the first node where `value` is found
* `NULL` if the value is not found or if the list is `NULL`

Every time a value is compared, it must be printed.

## Data Structure

The skip list uses the following structure:

```c id="5b5odn"
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;
```

## Skip List Concept

Searching in a regular singly linked list usually requires checking each node one by one.

A skip list improves this by adding express links between selected nodes.

In this project:

* the list is sorted in ascending order
* express nodes are placed at indexes that are multiples of the square root of the list size
* the search first moves through the express lane
* once the correct range is found, a normal linear search is performed inside that range

## Example

Given the following list:

```text id="8ecuja"
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]
```

Express lane:

```text id="4xuxfw"
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]
```

Searching for `53`:

```text id="v78gaa"
Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11
```

## Approach

The function searches in two phases.

First, it uses the express lane:

1. Start from the head of the skip list.
2. Move through express nodes while their values are smaller than the target.
3. Stop when the target value could be between the previous express node and the current one.
4. If the end of the express lane is reached, use the last node of the list as the upper boundary.

Then, it performs a regular linear search:

1. Start from the lower boundary.
2. Check each node one by one.
3. Stop when the value is found or when the upper boundary is reached.

This reduces the number of nodes that need to be checked compared to a full linear search.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="lm4dfe"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* All function prototypes must be included in `search.h`
* Header files must be include guarded

## Files

| File              | Description                                                             |
| ----------------- | ----------------------------------------------------------------------- |
| `0-linear_skip.c` | Contains the implementation of the `linear_skip` function.              |
| `search.h`        | Header file containing the skip list structure and function prototypes. |
| `0-main.c`        | Example test file.                                                      |

## Usage

Clone the repository and move into the project directory:

```bash id="66b1ai"
git clone <repository_url>
cd holbertonschool-interview/linear_skip
```

Compile the files:

```bash id="ut0l09"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
```

Run the program:

```bash id="r5rtp2"
./0-linear_skip
```

## Function Prototype

```c id="8091u8"
skiplist_t *linear_skip(skiplist_t *list, int value);
```

## Return Value

The function returns:

* a pointer to the node containing the searched value
* `NULL` if the value is not found
* `NULL` if the list is empty

## Algorithm Complexity

Let `n` be the number of nodes in the skip list.

With an express lane placed around every `sqrt(n)` nodes:

* Time complexity: `O(sqrt(n))`
* Space complexity: `O(1)`

The function only uses pointers and does not allocate additional memory.

## Learning Objectives

This project helps practice:

* linked list traversal
* skip list fundamentals
* express lane search logic
* pointer manipulation in C
* optimized search strategies
* formatted debug output
* handling edge cases
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
