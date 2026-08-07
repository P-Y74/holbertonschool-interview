# AVL Trees

## Description

This project focuses on checking whether a binary tree is a valid AVL tree.

An AVL tree is a self-balancing Binary Search Tree.
It must respect both Binary Search Tree rules and balance rules.

The goal is to write a function that verifies if a given binary tree satisfies all AVL tree properties.

## Problem Statement

Write a function that checks if a binary tree is a valid AVL tree.

Prototype:

```c id="ecxxvo"
int binary_tree_is_avl(const binary_tree_t *tree);
```

Where:

* `tree` is a pointer to the root node of the tree to check

The function must return:

* `1` if the tree is a valid AVL tree
* `0` if the tree is not a valid AVL tree
* `0` if `tree` is `NULL`

## AVL Tree Rules

A valid AVL tree must respect the following rules:

* it must be a Binary Search Tree
* the left subtree must contain only values smaller than the current node
* the right subtree must contain only values greater than the current node
* the height difference between the left and right subtrees must not be greater than `1`
* the left and right subtrees must also be valid AVL trees

In other words, every node in the tree must respect both:

```text id="qy5u1j"
BST property + balance property
```

## Data Structures

The project uses the following binary tree structure:

```c id="8h1g85"
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

Example of a valid AVL tree:

```text id="4se842"
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
```

Expected result:

```text id="pdwiig"
Is 98 avl: 1
```

If the Binary Search Tree property is broken, the tree is not AVL:

```text id="n3w70x"
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
```

Expected result:

```text id="aem9ze"
Is 98 avl: 0
```

If the tree becomes unbalanced, it is also not AVL:

```text id="9qs1s0"
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)--.
                              (430)
```

Expected result:

```text id="7vx2vn"
Is 98 avl: 0
```

## Approach

The function must check two conditions at the same time.

First, it verifies that the tree respects the Binary Search Tree rule:

1. All nodes in the left subtree must be smaller than the current node.
2. All nodes in the right subtree must be greater than the current node.
3. This rule must be true for every subtree.

Then, it verifies the AVL balance rule:

1. Compute the height of the left subtree.
2. Compute the height of the right subtree.
3. Check that the difference between both heights is not greater than `1`.
4. Repeat the same validation recursively for every node.

A tree is valid only if every node respects both the BST property and the AVL balance property.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash id="4wpg11"
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

| File                     | Description                                                     |
| ------------------------ | --------------------------------------------------------------- |
| `0-binary_tree_is_avl.c` | Contains the implementation of `binary_tree_is_avl`.            |
| `binary_trees.h`         | Header file containing tree structures and function prototypes. |
| `0-main.c`               | Example test file.                                              |
| `binary_tree_print.c`    | Helper function used only for visualization.                    |

## Usage

Clone the repository and move into the project directory:

```bash id="iyqpqp"
git clone <repository_url>
cd holbertonschool-interview/avl_trees
```

Compile the files:

```bash id="w0a1yf"
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c -L. -lavl -o 0-is_avl
```

Run the program:

```bash id="yqoabg"
./0-is_avl
```

## Function Prototype

```c id="lx29nd"
int binary_tree_is_avl(const binary_tree_t *tree);
```

## Return Value

The function returns an integer:

* `1` if the binary tree is a valid AVL tree
* `0` if the binary tree is not a valid AVL tree
* `0` if the tree is `NULL`

## Algorithm Complexity

Let `n` be the number of nodes in the tree.

Depending on the implementation:

* Time complexity: `O(n)` if height and validation are optimized together
* Time complexity: `O(n^2)` if the height is recalculated separately for every node
* Space complexity: `O(h)`, where `h` is the height of the tree, due to recursive calls

For a balanced AVL tree, `h` is approximately `log(n)`.

## Learning Objectives

This project helps practice:

* binary tree traversal
* Binary Search Tree validation
* AVL tree properties
* recursive algorithms
* height calculation
* balance factor checking
* pointer manipulation in C
* tree-based algorithm reasoning
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
