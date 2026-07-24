# Double Circular Linked List

## Description

This project focuses on creating and manipulating a double circular linked list in C.

A double circular linked list is a linked list where each node has:

* a pointer to the previous node
* a pointer to the next node

The list is circular, which means:

* the last node points back to the first node
* the first node points back to the last node

This structure allows traversal in both directions while keeping the list connected in a loop.

## Problem Statement

Create a source file that contains functions to add nodes to a double circular linked list.

The required functions are:

```c id="c4m9ks"
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);
```

The functions must:

* create a new node
* duplicate the given string
* insert the node at the beginning or at the end of the list
* preserve the circular structure
* preserve both `prev` and `next` links
* return the address of the new node
* return `NULL` on failure

## Data Structure

The project uses the following structure:

```c id="v8lq2p"
/**
 * struct List - doubly linked list
 * @str: string - malloc'ed string
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;
```

## Circular List Concept

In a regular doubly linked list, the first node has `prev` set to `NULL`, and the last node has `next` set to `NULL`.

In a double circular linked list:

```text id="6kr7br"
first->prev == last
last->next == first
```

Example:

```text id="1f6lxm"
Holberton <-> School <-> Full <-> Stack <-> Engineer
     ^                                           |
     |___________________________________________|
```

This means the list can continue looping from the last node back to the first one.

## Functions

### Add Node at the End

Prototype:

```c id="gk8f0k"
List *add_node_end(List **list, char *str);
```

This function adds a new node at the end of the list.

If the list is empty, the new node becomes the only node and points to itself:

```text id="sffcqf"
node->prev = node
node->next = node
```

If the list already contains nodes, the new node is inserted between the current last node and the first node.

### Add Node at the Beginning

Prototype:

```c id="ua6dvh"
List *add_node_begin(List **list, char *str);
```

This function adds a new node at the beginning of the list.

If the list is empty, the new node becomes the only node and points to itself.

If the list already contains nodes, the new node is inserted before the current head, and the list pointer is updated to point to the new node.

## Example

Compilation:

```bash id="e9nkkt"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
```

Execution:

```bash id="ep6z85"
./a.out
```

Example output when adding nodes to the end:

```text id="2fld0c"
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
```

Example output when adding nodes to the beginning:

```text id="gkax46"
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
```

## Approach

For each insertion, the function must correctly update four links:

* the new node's `next`
* the new node's `prev`
* the previous node's `next`
* the next node's `prev`

For insertion at the end:

1. Allocate memory for the new node.
2. Duplicate the given string.
3. If the list is empty, make the node point to itself.
4. Otherwise, find the last node using `(*list)->prev`.
5. Insert the new node between the last node and the head.

For insertion at the beginning:

1. Allocate memory for the new node.
2. Duplicate the given string.
3. If the list is empty, make the node point to itself.
4. Otherwise, insert the node before the current head.
5. Update the list pointer so the new node becomes the head.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="h83mq0"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* Only the following C standard library functions are allowed:

```text id="7cmjkq"
malloc, free, strdup
```

* Functions such as `printf`, `puts`, `calloc`, and `realloc` are forbidden
* All function prototypes must be included in `list.h`
* Header files must be include guarded

## Files

| File           | Description                                                          |
| -------------- | -------------------------------------------------------------------- |
| `0-add_node.c` | Contains the implementations of `add_node_end` and `add_node_begin`. |
| `list.h`       | Header file containing the list structure and function prototypes.   |
| `0-main.c`     | Example test file.                                                   |

## Usage

Clone the repository and move into the project directory:

```bash id="j3swl0"
git clone <repository_url>
cd holbertonschool-interview/double_circular_linked_list
```

Compile the files:

```bash id="g119f4"
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
```

Run the program:

```bash id="ndvzn5"
./a.out
```

## Function Prototypes

```c id="sd2hss"
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);
```

## Return Value

Each function returns:

* the address of the new node on success
* `NULL` on failure

Possible failures include:

* memory allocation failure
* string duplication failure
* invalid input

## Algorithm Complexity

Let `n` be the number of nodes in the list.

Because the list is circular and doubly linked, the last node can be accessed directly with:

```c id="8c5cln"
(*list)->prev
```

Therefore:

* Add at beginning: `O(1)`
* Add at end: `O(1)`
* Space complexity: `O(1)` per inserted node

Each insertion only updates pointers and allocates memory for one new node.

## Learning Objectives

This project helps practice:

* doubly linked lists
* circular linked list logic
* pointer manipulation in C
* dynamic memory allocation
* string duplication
* updating `prev` and `next` links
* handling empty-list edge cases
* maintaining list integrity
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
