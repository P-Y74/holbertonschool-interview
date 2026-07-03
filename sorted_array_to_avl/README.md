# Array to AVL

## Description

This project focuses on building an AVL tree from a sorted array.

An AVL tree is a self-balancing binary search tree where the height difference between the left and right subtrees of any node is limited.

In this project, the input array is already sorted and contains no duplicate values.
The goal is to build a balanced AVL tree directly from the array without using rotations.

## Problem Statement

Write a function that builds an AVL tree from a sorted array.

Prototype:

```c id="uvk2bf"
avl_t *sorted_array_to_avl(int *array, size_t size);
```

Where:

* `array` is a pointer to the first element of the sorted array
* `size` is the number of elements in the array

The function must return:

* a pointer to the root node of the created AVL tree
* `NULL` on failure

The array does not contain duplicate values.

## Data Structures

The project uses the following binary tree structure:

```c id="caz0yu"
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
typedef struct binary_tree_s avl_t;
```

## Example

Given the following sorted array:

```text id="qe809e"
1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98
```

The function builds a balanced AVL tree by selecting middle elements as roots of subtrees.

Example output:

```text id="v7h6tf"
(001)(002)(020)(021)(022)(032)(034)(047)(062)(068)(079)(084)(087)(091)(095)(098)
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)--.
(001)     (020)     (022)     (034)     (062)     (079)     (087)     (095)--.
                                                                           (098)
```

## Approach

Because the array is already sorted, the tree can be built recursively.

The idea is to:

1. Select the middle element of the array as the root.
2. Use the left half of the array to build the left subtree.
3. Use the right half of the array to build the right subtree.
4. Repeat the same process recursively for each subtree.
5. Correctly assign parent, left, and right pointers.

This approach naturally creates a balanced binary search tree without needing rotations.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="h7xc9p"
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* Only 3 functions are allowed in `0-sorted_array_to_avl.c`
* The standard library is allowed
* The function is not allowed to use rotations
* All function prototypes must be included in `binary_trees.h`
* Header files must be include guarded

## Files

| File                      | Description                                                     |
| ------------------------- | --------------------------------------------------------------- |
| `0-sorted_array_to_avl.c` | Contains the implementation of `sorted_array_to_avl`.           |
| `binary_trees.h`          | Header file containing tree structures and function prototypes. |
| `0-main.c`                | Example test file.                                              |
| `binary_tree_print.c`     | Helper function used only for visualization.                    |

## Usage

Clone the repository and move into the project directory:

```bash id="88n39j"
git clone <repository_url>
cd holbertonschool-interview/sorted_array_to_avl
```

Compile the files:

```bash id="vjssv4"
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```

Run the program:

```bash id="1obrvj"
./0-sorted_array_to_avl
```

## Function Prototype

```c id="6c0h2w"
avl_t *sorted_array_to_avl(int *array, size_t size);
```

## Return Value

The function returns:

* a pointer to the root node of the created AVL tree
* `NULL` if the array is `NULL`, if the size is invalid, or if memory allocation fails

## Algorithm Complexity

Let `n` be the number of elements in the array.

* Time complexity: `O(n)`
* Space complexity: `O(log n)` for the recursive call stack in a balanced tree

Each array element is used once to create one tree node.

## Learning Objectives

This project helps practice:

* binary search tree construction
* AVL tree fundamentals
* recursive algorithms
* working with sorted arrays
* pointer manipulation in C
* parent-child relationships in trees
* memory allocation and error handling
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
