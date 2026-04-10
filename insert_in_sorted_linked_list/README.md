# insert_in_sorted_linked_list

## Description

This project focuses on inserting a node into a **sorted singly linked list** while maintaining the correct order.

The objective is to understand how to traverse a linked list, handle edge cases, and correctly manipulate pointers during insertion.

## Educational Context

This project was completed as part of the Holberton School interview preparation curriculum.

It reflects a common technical interview problem requiring strong understanding of linked lists and pointer logic.

## Learning Objectives

By completing this project, the following concepts were practiced:

- singly linked list structure
- pointer manipulation in C
- traversal and insertion logic
- maintaining sorted order
- handling edge cases (head, empty list, end of list)
- memory allocation and node creation

## Data Structure

### Singly Linked List Node

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
````

## Project Task

### `0-insert_number.c`

Function to insert a number into a sorted singly linked list.

**Prototype:**

```c
listint_t *insert_node(listint_t **head, int number);
```

**Description:**

* creates a new node with the given value
* inserts it into the correct position in the list
* maintains ascending order
* returns the address of the new node
* returns NULL on failure

## Files Included

* `0-insert_number.c` → insertion logic
* `lists.h` → structure definition and prototypes
* `linked_lists.c` → helper functions (printing, creation, etc.)
* `0-main.c` → test file (for local testing)
* `insert` → compiled executable (optional)

## Requirements

* Compiled on **Ubuntu 14.04 LTS**
* Compiler: `gcc 4.8.4`
* Flags: `-Wall -Werror -Wextra -pedantic`
* No global variables
* Maximum 5 functions per file
* Code must follow **Betty style**
* All files must end with a new line
* Header files must be include guarded

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o insert
```

## Usage

Example:

```bash
./insert
```

(Requires a test `main.c` file)

## Key Concepts

### Sorted Insertion

The node must be inserted at the correct position to preserve ascending order.

### Edge Cases

* empty list
* insertion at the beginning (new head)
* insertion in the middle
* insertion at the end

### Pointer Manipulation

* updating `next` pointers carefully
* avoiding memory leaks
* ensuring list integrity after insertion

## Learning Outcomes

* solid understanding of linked list operations
* ability to manipulate pointers safely in C
* improved problem-solving for interview scenarios
* handling of edge cases in dynamic structures

## Project Status

This project is part of a broader interview preparation repository and may be extended with:

* deletion operations
* reverse linked list
* cycle detection (Floyd’s algorithm)

## Author

Pierre-Yves
