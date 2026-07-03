# Heap Extract

## Description

This project focuses on extracting the root node from a Max Binary Heap.

A Max Binary Heap is a complete binary tree where each parent node has a value greater than or equal to the values of its children.

In this project, the goal is to remove the root node, return its value, replace it with the last node in level-order traversal, and restore the heap property if needed.

## Problem Statement

Write a function that extracts the root node of a Max Binary Heap.

Prototype:

```c
int heap_extract(heap_t **root);
```

Where:

* `root` is a double pointer to the root node of the heap

The function must:

* return the value stored in the root node
* free the old root node
* replace the root with the last level-order node
* rebuild the heap if necessary
* return `0` on failure

## Data Structures

The project uses the following binary tree structure:

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
```

## Max Binary Heap Rule

In a Max Binary Heap:

* the highest value is always stored at the root
* each parent node must be greater than or equal to its children
* the tree must remain complete
* insertion and extraction must preserve the heap structure

Example:

```text
      98
    /    \
  95      91
 /  \    /  \
84  79  87  62
```

The extracted value is `98`.

After extraction, the root is replaced by the last level-order node, then the heap is rebuilt by moving the new root down until the Max Heap property is restored.

## Example

Compilation:

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap
```

Execution:

```bash
./0-heap_extract
```

Example output:

```text
Extracted: 98
Extracted: 95
Extracted: 91
```

Each extraction removes the current maximum value from the heap and reorganizes the tree.

## Approach

The extraction process follows several steps:

1. Check if the heap exists.
2. Store the value of the root node.
3. Find the last node in level-order traversal.
4. Replace the root value with the last node value.
5. Remove and free the last node.
6. Restore the Max Heap property using a sift-down operation.
7. Return the original root value.

The sift-down operation compares the current node with its children and swaps values with the largest child until the heap property is restored.

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
* The standard library is allowed
* All function prototypes must be included in `binary_trees.h`
* Header files must be include guarded

## Files

| File                  | Description                                                     |
| --------------------- | --------------------------------------------------------------- |
| `0-heap_extract.c`    | Contains the implementation of the `heap_extract` function.     |
| `binary_trees.h`      | Header file containing tree structures and function prototypes. |
| `0-main.c`            | Example test file.                                              |
| `binary_tree_print.c` | Helper function used only for visualization.                    |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/heap_extract
```

Compile the files:

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap
```

Run the program:

```bash
./0-heap_extract
```

To check for memory leaks:

```bash
valgrind ./0-heap_extract
```

## Function Prototype

```c
int heap_extract(heap_t **root);
```

## Return Value

The function returns:

* the value stored in the extracted root node
* `0` if the function fails or if the heap is empty

## Algorithm Complexity

Let `n` be the number of nodes in the heap.

* Time complexity: `O(log(n))` for restoring the heap property
* Space complexity: `O(1)` if the heap is traversed without additional dynamic memory

Finding the last node may require traversal depending on the implementation, but the heap restoration itself follows the height of the tree.

## Learning Objectives

This project helps practice:

* Max Binary Heap operations
* binary tree traversal
* root extraction logic
* finding the last level-order node
* maintaining complete tree structure
* sift-down heap rebuilding
* pointer manipulation in C
* memory management and freeing nodes
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
