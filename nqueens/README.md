N Queens
# N Queens

## Description

This project focuses on solving the classic N Queens puzzle using backtracking.

The goal is to place `N` queens on an `N x N` chessboard so that no two queens can attack each other.

A queen can attack another queen if they are on the same:

* row
* column
* diagonal

The program must print all possible valid solutions for a given board size.

## Problem Statement

Write a program that solves the N Queens problem.

Usage:

```bash
nqueens N
```

Where `N` is the size of the chessboard and the number of queens to place.

Rules:

* `N` must be an integer.
* `N` must be greater than or equal to `4`.
* The program must print every possible solution.
* One solution must be printed per line.
* Solutions do not need to be printed in a specific order.
* Only the `sys` module is allowed.

## Output Format

Each solution is represented as a list of queen positions.

Each queen position is written as:

```text
[row, column]
```

Example solution for `N = 4`:

```text
[[0, 1], [1, 3], [2, 0], [3, 2]]
```

This means:

* queen on row `0`, column `1`
* queen on row `1`, column `3`
* queen on row `2`, column `0`
* queen on row `3`, column `2`

## Examples

Run the program with `N = 4`:

```bash
./0-nqueens.py 4
```

Output:

```text
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

Run the program with `N = 6`:

```bash
./0-nqueens.py 6
```

Output:

```text
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

## Error Handling

If the program is called with the wrong number of arguments:

```bash
./0-nqueens.py
```

Output:

```text
Usage: nqueens N
```

The program exits with status `1`.

If `N` is not an integer:

```bash
./0-nqueens.py hello
```

Output:

```text
N must be a number
```

The program exits with status `1`.

If `N` is smaller than `4`:

```bash
./0-nqueens.py 3
```

Output:

```text
N must be at least 4
```

The program exits with status `1`.

## Approach

The problem is solved using backtracking.

The program places queens row by row.
For each row, it tries every possible column and checks whether the position is safe.

A position is valid if there is no queen already placed:

* in the same column
* on the same left diagonal
* on the same right diagonal

If a queen can be safely placed, the algorithm continues to the next row.

If no valid position is available, the algorithm backtracks by removing the last placed queen and trying another position.

This process continues until all valid solutions are found.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* Python 3.4.3
* All files must end with a new line
* The first line of all Python files must be:

```python
#!/usr/bin/python3
```

* Code must follow PEP 8 style
* All files must be executable
* Only the `sys` module is allowed

## Files

| File           | Description                                      |
| -------------- | ------------------------------------------------ |
| `0-nqueens.py` | Python program that solves the N Queens problem. |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/nqueens
```

Make the file executable if needed:

```bash
chmod +x 0-nqueens.py
```

Run the program:

```bash
./0-nqueens.py 4
```

## Algorithm Complexity

The N Queens problem has a combinatorial search space.

* Time complexity: `O(N!)` in the typical backtracking approach
* Space complexity: `O(N)`

The space complexity comes from storing the current queen positions during the recursive search.

## Learning Objectives

This project helps practice:

* backtracking
* recursion
* constraint checking
* algorithmic problem solving
* command-line argument handling
* input validation
* Python scripting
* technical interview preparation

## Author

Pierre-Yves
