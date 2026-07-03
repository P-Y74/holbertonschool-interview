# Rotate 2D Matrix

## Description

This project focuses on rotating a square 2D matrix 90 degrees clockwise.

The matrix must be modified in place, meaning the function should directly update the original matrix without returning a new one.

This exercise is useful for practicing matrix manipulation, index management, and in-place algorithms in Python.

## Problem Statement

Write a function that rotates an `n x n` 2D matrix 90 degrees clockwise.

Prototype:

```python id="hixn4z"
def rotate_2d_matrix(matrix):
```

Where:

* `matrix` is a non-empty 2D list
* the matrix has `n` rows and `n` columns
* the matrix must be edited in place

The function must not return anything.

## Example

Given the following matrix:

```python id="0oq384"
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]
```

After rotation:

```python id="m1fgxa"
[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
```

Execution example:

```bash id="5ki5mi"
./main_0.py
```

Output:

```text id="5k8mms"
[[7, 4, 1], [8, 5, 2], [9, 6, 3]]
```

## Rotation Logic

A 90-degree clockwise rotation transforms rows into columns.

Original matrix:

```text id="erjo25"
1 2 3
4 5 6
7 8 9
```

Rotated matrix:

```text id="4ynxq0"
7 4 1
8 5 2
9 6 3
```

The first row becomes the last column, the second row becomes the middle column, and the last row becomes the first column.

## Approach

A common in-place approach is to rotate the matrix in two steps:

1. Transpose the matrix.
2. Reverse each row.

Example:

Original matrix:

```text id="v1ttjg"
1 2 3
4 5 6
7 8 9
```

After transposition:

```text id="57bq1l"
1 4 7
2 5 8
3 6 9
```

After reversing each row:

```text id="hu0e4a"
7 4 1
8 5 2
9 6 3
```

This produces a 90-degree clockwise rotation without creating a new matrix.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* Python 3.4.3
* All files must end with a new line
* The first line of all Python files must be:

```python id="z9n7bs"
#!/usr/bin/python3
```

* Code must follow PEP 8 style
* No module imports are allowed
* All modules and functions must be documented
* All files must be executable

## Files

| File                    | Description                                                     |
| ----------------------- | --------------------------------------------------------------- |
| `0-rotate_2d_matrix.py` | Contains the implementation of the `rotate_2d_matrix` function. |
| `main_0.py`             | Example test file.                                              |

## Usage

Clone the repository and move into the project directory:

```bash id="ryq4fd"
git clone <repository_url>
cd holbertonschool-interview/rotate_2d_matrix
```

Make the files executable if needed:

```bash id="h6q6xd"
chmod +x 0-rotate_2d_matrix.py main_0.py
```

Run the test file:

```bash id="qwe6n8"
./main_0.py
```

Example output:

```text id="1f3vmb"
[[7, 4, 1], [8, 5, 2], [9, 6, 3]]
```

## Function Prototype

```python id="v9ue38"
def rotate_2d_matrix(matrix):
```

## Return Value

This function does not return anything.

The original matrix is modified directly in place.

## Algorithm Complexity

Let `n` be the size of the matrix.

* Time complexity: `O(n^2)`
* Space complexity: `O(1)`

The matrix is updated in place, without creating another `n x n` matrix.

## Learning Objectives

This project helps practice:

* matrix manipulation
* nested loops
* index swapping
* in-place algorithms
* transposition
* row reversal
* Python list handling
* technical interview preparation

## Author

Pierre-Yves
