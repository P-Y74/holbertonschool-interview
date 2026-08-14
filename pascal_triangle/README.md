# Pascal's Triangle

## Description

This project focuses on generating Pascal's Triangle using Python.

Pascal's Triangle is a triangular array of numbers where each number is the sum of the two numbers directly above it.

The triangle starts with `1`, and each row begins and ends with `1`.

## Problem Statement

Create a function that returns a list of lists of integers representing Pascal's Triangle of size `n`.

Prototype:

```python
def pascal_triangle(n):
```

The function must return:

* a list of lists representing Pascal's Triangle
* an empty list if `n <= 0`

You can assume that `n` will always be an integer.

## Pascal's Triangle Rule

Each row is built from the previous row.

The first and last values of every row are always `1`.

Each middle value is calculated by adding the two values above it:

```text
new_value = previous_row[index - 1] + previous_row[index]
```

Example:

```text
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
```

## Example

Test file:

```python
#!/usr/bin/python3
"""
0-main
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle


def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))
```

Expected output:

```text
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
```

## Approach

The function builds the triangle row by row.

General logic:

1. If `n <= 0`, return an empty list.
2. Start with an empty triangle.
3. For each row index from `0` to `n - 1`:

   * create a new row
   * place `1` at the beginning and end
   * calculate middle values from the previous row
4. Add each row to the triangle.
5. Return the completed triangle.

This approach avoids hardcoding values and works for any valid integer `n`.

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
* All modules and functions must be documented
* All files must be executable

## Files

| File                   | Description                                                    |
| ---------------------- | -------------------------------------------------------------- |
| `0-pascal_triangle.py` | Contains the implementation of the `pascal_triangle` function. |
| `0-main.py`            | Example test file.                                             |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/pascal_triangle
```

Make the files executable if needed:

```bash
chmod +x 0-pascal_triangle.py 0-main.py
```

Run the test file:

```bash
./0-main.py
```

## Function Prototype

```python
def pascal_triangle(n):
```

## Return Value

The function returns:

* a list of lists of integers representing Pascal's Triangle
* an empty list if `n <= 0`

Example return value for `n = 5`:

```python
[
    [1],
    [1, 1],
    [1, 2, 1],
    [1, 3, 3, 1],
    [1, 4, 6, 4, 1]
]
```

## Algorithm Complexity

Let `n` be the number of rows.

The total number of values generated is:

```text
1 + 2 + 3 + ... + n
```

Therefore:

* Time complexity: `O(n^2)`
* Space complexity: `O(n^2)`

The function stores all rows of the triangle in memory.

## Learning Objectives

This project helps practice:

* list manipulation in Python
* nested loops
* mathematical pattern generation
* building data structures incrementally
* edge case handling
* writing documented Python functions
* technical interview preparation

## Author

Pierre-Yves
