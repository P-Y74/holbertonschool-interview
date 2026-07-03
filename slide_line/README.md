# 2048 Single Line

## Description

This project focuses on reproducing the slide and merge mechanics of the game `2048`, but on a single horizontal line.

Given an array of integers, the goal is to slide all values either to the left or to the right, merge identical values when possible, and fill the remaining positions with zeros.

This exercise is useful for practicing array manipulation, in-place updates, edge case handling, and algorithmic logic in C.

## Problem Statement

Write a function that slides and merges an array of integers in a given direction.

Prototype:

```c
int slide_line(int *line, size_t size, int direction);
```

Where:

* `line` is a pointer to an array of integers
* `size` is the number of elements in the array
* `direction` indicates the direction of the slide

The direction can be either:

```c
SLIDE_LEFT
SLIDE_RIGHT
```

Both macros must be defined in `slide_line.h`.

The function must return:

* `1` on success
* `0` on failure

The function must fail if the direction is invalid.

Dynamic memory allocation is not allowed.

## 2048 Merge Rules

The function must follow the classic `2048` merge behavior:

* zeros are ignored during the slide
* identical numbers can merge if they become adjacent after sliding
* each number can merge only once per move
* after merging, the remaining empty spaces are filled with zeros

Example:

```text
2, 2, 0, 0
```

Slide left:

```text
4, 0, 0, 0
```

Another example:

```text
2, 2, 2, 2
```

Slide right:

```text
0, 0, 4, 4
```

## Example

Compilation:

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
```

Slide to the left:

```bash
./0-slide_line L 2 2 0 0
```

Output:

```text
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0
```

Slide to the right:

```bash
./0-slide_line R 2 2 2 2
```

Output:

```text
Line: 2, 2, 2, 2
Slide to the right
Line: 0, 0, 4, 4
```

## Approach

The function processes the array in the requested direction.

For a left slide, the array is read from left to right.
For a right slide, the array is read from right to left.

The general logic is:

1. Move all non-zero values toward the requested direction.
2. Merge identical adjacent values once.
3. Shift the result again to remove gaps created by merges.
4. Fill the remaining positions with zeros.

The operation is performed directly inside the original array.

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
* All function prototypes must be included in `slide_line.h`
* Header files must be include guarded

## Files

| File             | Description                                                         |
| ---------------- | ------------------------------------------------------------------- |
| `0-slide_line.c` | Contains the implementation of the `slide_line` function.           |
| `slide_line.h`   | Header file containing the function prototype and direction macros. |
| `0-main.c`       | Example test file.                                                  |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/slide_line
```

Compile the files:

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
```

Run the program with a direction and a list of numbers:

```bash
./0-slide_line L 2 2 0 0
```

Example output:

```text
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0
```

Another test:

```bash
./0-slide_line R 2 2 2 2 2
```

Output:

```text
Line: 2, 2, 2, 2, 2
Slide to the right
Line: 0, 0, 2, 4, 4
```

## Function Prototype

```c
int slide_line(int *line, size_t size, int direction);
```

## Direction Macros

The following macros must be defined in `slide_line.h`:

```c
#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1
```

## Return Value

The function returns an integer:

* `1` if the slide and merge operation succeeds
* `0` if the direction is invalid or if the operation fails

## Algorithm Complexity

Let `n` be the number of elements in the array.

* Time complexity: `O(n)`
* Space complexity: `O(1)`

The function works in place and does not allocate additional memory dynamically.

## Learning Objectives

This project helps practice:

* array manipulation in C
* in-place algorithms
* conditional merging logic
* edge case handling
* implementing game mechanics
* working with macros and header files
* respecting strict C compilation and Betty style requirements

## Author

Pierre-Yves
