# Find the Loop

## Description

This project focuses on detecting the starting point of a loop in a singly linked list.

A linked list contains a loop when one of its nodes points back to a previous node instead of eventually pointing to `NULL`.

The goal is not only to detect whether a loop exists, but also to return the exact node where the loop begins.

## Problem Statement

Write a function that finds the loop in a linked list.

Prototype:

```c id="ks54au"
listint_t *find_listint_loop(listint_t *head);
```

The function must return:

* the address of the node where the loop starts
* `NULL` if there is no loop

## Data Structure

The linked list uses the following structure:

```c id="qhnys8"
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

A normal linked list ends with `NULL`:

```text id="n2mlw2"
1024 -> 402 -> 98 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
```

A linked list with a loop points back to a previous node:

```text id="rzryuw"
1024 -> 402 -> 98 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0
               ^                                      |
               |______________________________________|
```

In this case, the loop starts at the node containing `7`.

Example output:

```text id="x8eueg"
Loop starts at [address] 7
```

## Approach

The function can be solved using Floyd’s Cycle Detection Algorithm, also known as the tortoise and hare algorithm.

The process works in two phases.

First, two pointers move through the list at different speeds:

* one slow pointer moves one node at a time
* one fast pointer moves two nodes at a time

If there is no loop, the fast pointer eventually reaches `NULL`.

If there is a loop, the two pointers eventually meet inside the cycle.

Once a meeting point is found:

1. Move one pointer back to the head of the list.
2. Keep the other pointer at the meeting point.
3. Move both pointers one node at a time.
4. The node where they meet again is the start of the loop.

This allows the function to find the loop start without using arrays or extra memory.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="u2045b"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* No standard library functions are allowed
* Functions such as `printf`, `puts`, `calloc`, and `realloc` are forbidden
* `malloc`, `free`, and arrays are not allowed inside the solution
* A maximum of two variables can be declared in the function
* All function prototypes must be included in `lists.h`
* Header files must be include guarded

## Files

| File            | Description                                                               |
| --------------- | ------------------------------------------------------------------------- |
| `0-find_loop.c` | Contains the implementation of `find_listint_loop`.                       |
| `lists.h`       | Header file containing the linked list structure and function prototypes. |
| `0-main.c`      | Example test file.                                                        |
| `lib.c`         | Optional helper file for local testing instead of the static library.     |

## Usage

Clone the repository and move into the project directory:

```bash id="2j7snx"
git clone <repository_url>
cd holbertonschool-interview/find_the_loop
```

Compile with the provided testing library:

```bash id="t3hh7y"
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c -L. -lloop -o main
```

Run the program:

```bash id="vcf6x7"
./main
```

You can also compile with the helper source file:

```bash id="l7f5h7"
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main
```

## Function Prototype

```c id="y9wqed"
listint_t *find_listint_loop(listint_t *head);
```

## Return Value

The function returns:

* a pointer to the node where the loop starts
* `NULL` if the linked list has no loop
* `NULL` if the list is empty

## Algorithm Complexity

Let `n` be the number of nodes in the linked list.

* Time complexity: `O(n)`
* Space complexity: `O(1)`

The solution only uses pointer movement and does not allocate additional memory.

## Learning Objectives

This project helps practice:

* singly linked list traversal
* pointer manipulation in C
* loop detection
* finding the start of a cycle
* Floyd’s tortoise and hare algorithm
* memory-efficient algorithms
* solving constraints without arrays or allocation
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
