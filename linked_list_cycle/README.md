# Linked List Cycle

## Description

This project focuses on detecting whether a singly linked list contains a cycle.

A cycle exists when a node in the linked list points back to a previous node instead of eventually pointing to `NULL`.
This can cause infinite loops during traversal if the cycle is not detected properly.

The goal is to solve this problem efficiently in C without unnecessary memory usage.

## Problem Statement

Write a function that checks if a singly linked list has a cycle.

Prototype:

```c
int check_cycle(listint_t *list);
```

The function must return:

* `1` if the linked list contains a cycle
* `0` if the linked list does not contain a cycle

## Data Structure

The linked list uses the following structure:

```c
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Example

Given the following linked list:

```text
1024 -> 402 -> 98 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
```

The list has no cycle.

If one node is modified to point back to the head of the list:

```text
1024 -> 402 -> 98 -> 4
 ^                    |
 |                    v
 0 <- 1 <- 2 <- 3 <---
```

The list now contains a cycle.

Expected output:

```text
Linked list has no cycle
Linked list has a cycle
```

## Approach

A common efficient solution is to use Floyd’s Cycle Detection Algorithm, also known as the tortoise and hare algorithm.

The idea is to use two pointers:

* a slow pointer that moves one node at a time
* a fast pointer that moves two nodes at a time

If the linked list has no cycle, the fast pointer will eventually reach `NULL`.

If the linked list has a cycle, the fast pointer will eventually meet the slow pointer inside the cycle.

This approach is efficient because it does not require storing visited nodes.

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
* All function prototypes must be included in `lists.h`
* Header files must be include guarded

Allowed functions:

```text
write, printf, putchar, puts, malloc, free
```

## Files

| File               | Description                                                               |
| ------------------ | ------------------------------------------------------------------------- |
| `0-check_cycle.c`  | Contains the implementation of the `check_cycle` function.                |
| `lists.h`          | Header file containing the linked list structure and function prototypes. |
| `0-linked_lists.c` | Helper functions used for testing linked lists.                           |
| `0-main.c`         | Example test file.                                                        |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/linked_list_cycle
```

Compile the files:

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

Run the program:

```bash
./cycle
```

Example output:

```text
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

## Function Prototype

```c
int check_cycle(listint_t *list);
```

## Return Value

The function returns an integer:

* `1` if a cycle is detected
* `0` if no cycle is detected

## Algorithm Complexity

Let `n` be the number of nodes in the linked list.

* Time complexity: `O(n)`
* Space complexity: `O(1)`

The solution only uses two pointers and does not require additional memory allocation.

## Learning Objectives

This project helps practice:

* singly linked list traversal
* pointer manipulation in C
* cycle detection
* Floyd’s tortoise and hare algorithm
* efficient memory usage
* handling edge cases
* writing interview-style algorithms
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
