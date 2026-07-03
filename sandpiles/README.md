# Sandpiles

## Description

This project focuses on computing the sum of two stable sandpiles represented as `3x3` grids.

A sandpile is considered stable when none of its cells contains more than `3` grains.
After adding two sandpiles together, some cells may become unstable and must be toppled until the whole grid becomes stable again.

The result is stored directly in `grid1`.

## Problem Statement

Write a function that computes the sum of two sandpiles.

Prototype:

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

Rules:

* `grid1` and `grid2` are both individually stable before the sum.
* After the function completes, `grid1` must be stable.
* If `grid1` becomes unstable, it must be printed before each toppling round.
* Dynamic memory allocation is not allowed.

## Sandpile Toppling Rule

A cell is unstable when its value is greater than `3`.

When a cell topples:

* it loses `4` grains
* each valid adjacent cell receives `1` grain

Adjacent cells are:

* top
* bottom
* left
* right

Diagonal cells are not affected.

Example of a toppling cell:

```text
  0
0 4 0
  0
```

After toppling:

```text
  1
1 0 1
  1
```

## Approach

The function first adds `grid2` into `grid1`.

Then, while `grid1` is unstable:

1. Print the current unstable grid.
2. Identify all cells that need to topple.
3. Apply all toppling operations simultaneously.
4. Repeat until the grid is stable.

A temporary `3x3` grid can be used to make sure all unstable cells topple during the same round, without interfering with each other during the calculation.

## Example

Initial grids:

```text
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
```

Output:

```text
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

Final stable grid:

```text
2 2 2
2 2 2
2 2 2
```

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
* Dynamic memory allocation is not allowed
* All function prototypes must be included in `sandpiles.h`
* Header files must be include guarded

## Files

| File            | Description                                     |
| --------------- | ----------------------------------------------- |
| `0-sandpiles.c` | Contains the implementation of `sandpiles_sum`. |
| `sandpiles.h`   | Header file containing function prototypes.     |
| `0-main.c`      | Example test file.                              |
| `1-main.c`      | Additional example test file.                   |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/sandpiles
```

Compile with:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
```

Run the program:

```bash
./0-sandpiles
```

## Function Prototype

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

## Return Value

This function does not return a value.

The final stable sandpile is stored directly inside `grid1`.

## Algorithm Complexity

Because the grid size is fixed at `3x3`, the space used remains constant.

* Time complexity: `O(k)`, where `k` is the number of toppling rounds needed to stabilize the grid
* Space complexity: `O(1)`

## Learning Objectives

This project helps practice:

* working with 2D arrays in C
* implementing simulation logic
* applying simultaneous state updates
* handling fixed-size grids
* understanding stabilization algorithms
* respecting strict C compilation and style requirements

## Author

Pierre-Yves
