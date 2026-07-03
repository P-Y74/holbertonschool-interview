# holbertonschool_interview

## Description

This repository contains algorithmic and technical interview practice projects completed as part of the Holberton School curriculum.

It includes exercises focused on problem solving, data structures, recursion, sorting algorithms, search algorithms, linked lists, binary trees, graph-like traversal, and implementation logic commonly encountered in coding interviews.

The repository contains projects written mainly in **C** and **Python**, with one JavaScript-based API exercise.

## Educational Context

This work was completed as part of the Holberton School curriculum.

The purpose of this repository is to strengthen algorithmic thinking, improve understanding of core data structures, and practice solving technical problems with clean and efficient implementations.

Each project focuses on a specific challenge and helps develop practical interview preparation skills through hands-on implementation.

## Repository Structure

The repository is organized by project directory.

### Search Algorithms

| Project                                              | Description                                                                                           |
| ---------------------------------------------------- | ----------------------------------------------------------------------------------------------------- |
| [`advanced_binary_search`](./advanced_binary_search) | Advanced binary search implementation that returns the first occurrence of a value in a sorted array. |
| [`linear_skip`](./linear_skip)                       | Search algorithm implementation using a skip list-like linked list structure.                         |

### Sorting Algorithms

| Project                      | Description                                                                |
| ---------------------------- | -------------------------------------------------------------------------- |
| [`heap_sort`](./heap_sort)   | Implementation of the Heap Sort algorithm using a binary heap.             |
| [`merge_sort`](./merge_sort) | Implementation of the Merge Sort algorithm using divide-and-conquer logic. |

### Linked Lists

| Project                                                          | Description                                                             |
| ---------------------------------------------------------------- | ----------------------------------------------------------------------- |
| [`insert_in_sorted_linked_list`](./insert_in_sorted_linked_list) | Inserts a node into a sorted singly linked list while preserving order. |
| [`linked_list_cycle`](./linked_list_cycle)                       | Detects whether a singly linked list contains a cycle.                  |
| [`linked_list_palindrome`](./linked_list_palindrome)             | Checks whether a singly linked list represents a palindrome.            |
| [`find_the_loop`](./find_the_loop)                               | Finds the starting node of a loop inside a linked list.                 |

### Binary Trees and Heaps

| Project                                        | Description                                                                    |
| ---------------------------------------------- | ------------------------------------------------------------------------------ |
| [`heap_insert`](./heap_insert)                 | Inserts a value into a Max Binary Heap while preserving heap properties.       |
| [`heap_extract`](./heap_extract)               | Extracts the root node from a Max Binary Heap and restores the heap structure. |
| [`sorted_array_to_avl`](./sorted_array_to_avl) | Builds an AVL tree from a sorted array.                                        |

### Dynamic Programming, Recursion and Backtracking

| Project                                      | Description                                                                                |
| -------------------------------------------- | ------------------------------------------------------------------------------------------ |
| [`minimum_operations`](./minimum_operations) | Calculates the minimum number of operations needed to reach a target number of characters. |
| [`nqueens`](./nqueens)                       | Solves the N Queens problem using backtracking.                                            |
| [`menger`](./menger)                         | Prints a 2D Menger sponge pattern using recursive logic.                                   |
| [`sandpiles`](./sandpiles)                   | Computes the sum of two sandpiles and stabilizes the result.                               |

### Arrays, Matrices and Grid Problems

| Project                                  | Description                                                      |
| ---------------------------------------- | ---------------------------------------------------------------- |
| [`rotate_2d_matrix`](./rotate_2d_matrix) | Rotates a 2D matrix 90 degrees clockwise in place.               |
| [`rain`](./rain)                         | Calculates how much rainwater can be trapped between walls.      |
| [`slide_line`](./slide_line)             | Implements the logic behind a single line move in the 2048 game. |

### Numbers and Strings

| Project                                                | Description                                                    |
| ------------------------------------------------------ | -------------------------------------------------------------- |
| [`palindrome_integer`](./palindrome_integer)           | Checks whether an unsigned integer is a palindrome.            |
| [`infinite_multiplication`](./infinite_multiplication) | Multiplies two positive numbers represented as strings.        |
| [`utf8_validation`](./utf8_validation)                 | Validates whether a dataset represents a valid UTF-8 encoding. |

### Graph-Like Traversal and Data Processing

| Project                        | Description                                                                          |
| ------------------------------ | ------------------------------------------------------------------------------------ |
| [`lockboxes`](./lockboxes)     | Determines whether all boxes can be opened using available keys.                     |
| [`log_parsing`](./log_parsing) | Parses logs from standard input and computes metrics in real time.                   |
| [`count_it`](./count_it)       | Uses recursion and an external API to count keyword occurrences in Reddit hot posts. |

### API and Scripting

| Project                          | Description                                                       |
| -------------------------------- | ----------------------------------------------------------------- |
| [`starwars_api`](./starwars_api) | Uses the Star Wars API to print characters from a specific movie. |

## Learning Objectives

Through these projects, this repository helps develop:

* problem-solving methodology
* algorithmic thinking
* understanding of common data structures
* recursion and backtracking logic
* sorting and searching techniques
* pointer manipulation in C
* memory management awareness
* edge case handling
* API usage and scripting basics
* technical interview preparation skills

## Tech Stack

Depending on the project, the repository includes:

* C
* Python
* JavaScript
* Bash commands for compilation and execution

## Usage

Clone the repository:

```bash
git clone <repository_url>
cd holbertonschool_interview
```

Then navigate to the project directory you want to test.

Example with a C project:

```bash
cd heap_sort
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o heap_sort
./heap_sort
```

Example with a Python project:

```bash
cd lockboxes
python3 main_0.py
```

Each project directory may contain its own `README.md`, source files, header files, and test files.

## Project Status

This repository is actively evolving and will continue to be updated as new interview preparation projects are completed.

## Author

Pierre-Yves
