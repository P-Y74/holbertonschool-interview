# Menger Sponge

## Description

This project focuses on drawing a 2D version of the Menger sponge.

A Menger sponge is a fractal pattern built recursively.
In this project, the sponge is printed in the terminal using the `#` character for filled areas and spaces for empty areas.

Although the real Menger sponge is a 3D fractal, this exercise uses the same principle in a 2D grid.

## Problem Statement

Write a function that draws a 2D Menger sponge of a given level.

Prototype:

```c
void menger(int level);
```

Where:

* `level` is the level of the Menger sponge to draw
* if `level` is lower than `0`, the function must do nothing

The size of a level `N` Menger sponge is:

```text
3^N
```

For example:

| Level | Size      |
| ----- | --------- |
| `0`   | `1 x 1`   |
| `1`   | `3 x 3`   |
| `2`   | `9 x 9`   |
| `3`   | `27 x 27` |

## Menger Sponge Rule

A level `0` sponge is represented by a single `#`:

```text
#
```

A level `N` sponge is a `3 x 3` square made of level `N - 1` sponges, except for the center square, which is left empty.

This rule is applied recursively at each scale.

## Examples

Level `0`:

```bash
./0-menger 0
```

Output:

```text
#
```

Level `1`:

```bash
./0-menger 1
```

Output:

```text
###
# #
###
```

Level `2`:

```bash
./0-menger 2
```

Output:

```text
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

If the level is negative, nothing is printed:

```bash
./0-menger -1
```

## Approach

The function prints the pattern row by row and column by column.

For each position in the grid, the algorithm determines whether the current cell should be filled with `#` or left empty.

A cell must be empty when, at any recursive scale, it falls into the center of a `3 x 3` block.

This can be checked using division and modulo operations:

1. Compute the size of the sponge with `3^level`.
2. Iterate through each row and column.
3. For each coordinate, check whether it belongs to a center block.
4. Print a space if it is inside a removed center block.
5. Otherwise, print `#`.

This avoids storing the full grid in memory and prints the result directly.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash
-Wall -Werror -Wextra -pedantic
```

* The program will be compiled with the math library:

```bash
-lm
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* All function prototypes must be included in `menger.h`
* Header files must be include guarded

## Files

| File         | Description                                           |
| ------------ | ----------------------------------------------------- |
| `0-menger.c` | Contains the implementation of the `menger` function. |
| `menger.h`   | Header file containing the function prototype.        |
| `0-main.c`   | Example test file.                                    |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/menger
```

Compile the files:

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

Run the program with a level:

```bash
./0-menger 2
```

Example output:

```text
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

## Function Prototype

```c
void menger(int level);
```

## Return Value

This function does not return a value.

It prints the 2D Menger sponge directly to standard output.

## Algorithm Complexity

Let `n` be the size of the grid, where:

```text
n = 3^level
```

The function checks every cell of the `n x n` grid.

* Time complexity: `O(n^2)`
* Space complexity: `O(1)`

The pattern is printed directly without dynamically allocating memory for the full grid.

## Learning Objectives

This project helps practice:

* fractal pattern generation
* nested loops
* coordinate-based logic
* modulo and division operations
* using the math library in C
* printing structured output
* avoiding unnecessary memory allocation
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
