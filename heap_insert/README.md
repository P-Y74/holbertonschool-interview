# heap_insert

## Description

This project focuses on implementing insertion operations in a **Max Binary Heap** using a binary tree structure in C.

The goal is to understand how heaps work internally, including node creation, tree traversal, and maintaining heap properties during insertion.

## Educational Context

This project was completed as part of the Holberton School interview preparation curriculum.

It emphasizes algorithmic thinking, pointer manipulation, and data structure implementation commonly encountered in technical interviews.

## Learning Objectives

By completing this project, the following concepts were practiced:

- binary tree structures
- max binary heap properties
- dynamic memory allocation in C
- pointer manipulation
- tree traversal techniques
- maintaining heap ordering after insertion
- handling edge cases in tree-based structures

## Data Structures

### Binary Tree Node

```c
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
````

### Max Binary Heap

```c
typedef struct binary_tree_s heap_t;
```

## Project Tasks

### `0-binary_tree_node.c`

Function to create a new binary tree node.

**Prototype:**

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

**Description:**

* allocates memory for a new node
* initializes its value
* sets parent pointer
* initializes children to NULL

---

### `1-heap_insert.c`

Function to insert a value into a Max Binary Heap.

**Prototype:**

```c
heap_t *heap_insert(heap_t **root, int value);
```

**Description:**

* inserts a new node in level-order (complete tree property)
* ensures the tree remains complete
* restores heap property by bubbling up the inserted node
* returns pointer to inserted node

## Files Included

* `0-binary_tree_node.c` → node creation
* `1-heap_insert.c` → heap insertion logic
* `binary_trees.h` → data structures and function prototypes
* `binary_tree_print.c` → helper function for visualization (not required for submission)
* `1-main.c` → test file (for local testing)

## Requirements

* Compiled on **Ubuntu 14.04 LTS**
* Compiler: `gcc 4.8.4`
* Flags: `-Wall -Werror -Wextra -pedantic`
* No global variables
* Maximum 5 functions per file (6 allowed for heap_insert)
* Code must follow **Betty style**
* All files must end with a new line

## Compilation

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o heap
```

## Usage

Example:

```bash
./heap
```

(Requires a test `main.c` file)

## Key Concepts

### Max Heap Property

Each parent node must be greater than or equal to its children.

### Complete Binary Tree

* nodes are filled level by level
* insertion happens from left to right

### Heap Insertion Strategy

1. Insert node at the correct position (level-order)
2. Restore heap property:

   * compare with parent
   * swap values if needed
   * repeat until heap is valid

## Learning Outcomes

* deeper understanding of tree-based data structures
* ability to manipulate pointers in complex structures
* implementation of heap insertion logic
* improved problem-solving skills for interviews

## Project Status

This project is part of a larger interview preparation repository and may be extended with:

* heap extraction
* heap sort implementation
* priority queue abstraction

## Author

Pierre-Yves
