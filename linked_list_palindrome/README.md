# Linked List Palindrome

## Description

This project focuses on checking whether a singly linked list is a palindrome.

A linked list is considered a palindrome when its values can be read the same way from the beginning to the end and from the end to the beginning.

The goal is to solve this problem in C while working with pointers, linked list traversal, and edge cases.

## Problem Statement

Write a function that checks if a singly linked list is a palindrome.

Prototype:

```c
int is_palindrome(listint_t **head);
```

The function must return:

* `1` if the linked list is a palindrome
* `0` if the linked list is not a palindrome

An empty list is considered a palindrome.

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
1 -> 17 -> 972 -> 50 -> 98 -> 98 -> 50 -> 972 -> 17 -> 1
```

The list is a palindrome because the values are the same when read in both directions.

Expected output:

```text
Linked list is a palindrome
```

## Approach

The function checks the values stored in the linked list and compares them in a way that determines whether the list reads the same forward and backward.

A typical efficient approach is to:

1. Traverse the list to find its middle.
2. Reverse one half of the list.
3. Compare the first half with the reversed second half.
4. Return the result of the comparison.

This avoids converting the list into another data structure and keeps the solution focused on linked list manipulation.

Special cases to handle:

* empty list
* list with one node
* list with an even number of nodes
* list with an odd number of nodes
* lists that are almost palindromes but contain one different value

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

## Files

| File                | Description                                                               |
| ------------------- | ------------------------------------------------------------------------- |
| `0-is_palindrome.c` | Contains the implementation of the `is_palindrome` function.              |
| `lists.h`           | Header file containing the linked list structure and function prototypes. |
| `linked_lists.c`    | Helper functions used for testing linked lists.                           |
| `0-main.c`          | Example test file.                                                        |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/linked_list_palindrome
```

Compile the files:

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

Run the program:

```bash
./palindrome
```

Example output:

```text
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```

## Function Prototype

```c
int is_palindrome(listint_t **head);
```

## Return Value

The function returns an integer:

* `1` if the linked list is a palindrome
* `0` if the linked list is not a palindrome

## Algorithm Complexity

Depending on the implementation strategy:

* Time complexity: `O(n)`, where `n` is the number of nodes in the list
* Space complexity: `O(1)` when reversing part of the list in place

## Learning Objectives

This project helps practice:

* singly linked list traversal
* pointer manipulation in C
* detecting edge cases
* reversing linked list segments
* comparing node values
* writing efficient interview-style algorithms
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
