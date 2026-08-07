# Island Perimeter

## Description

This project focuses on calculating the perimeter of an island represented in a 2D grid.

The grid contains water and land cells:

* `0` represents water
* `1` represents land

Each land cell is a square with a side length of `1`.
Land cells are connected horizontally or vertically, but not diagonally.

The goal is to return the total perimeter of the island.

## Problem Statement

Write a function that returns the perimeter of the island described in `grid`.

Prototype:

```python id="w3q6jr"
def island_perimeter(grid):
```

Where:

* `grid` is a list of lists of integers
* `0` represents water
* `1` represents land

The function must return the perimeter of the island as an integer.

## Grid Rules

The grid follows these rules:

* the grid is rectangular
* its width and height do not exceed `100`
* the grid is completely surrounded by water
* there is only one island, or no island
* the island does not contain lakes
* cells are connected horizontally or vertically only
* diagonal connections do not count

## Example

Given this grid:

```python id="vodj40"
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
```

Visual representation:

```text id="sd6wde"
0 0 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 1 1 1 0 0
0 0 0 0 0 0
```

Expected output:

```text id="q82ypc"
12
```

## Approach

The function scans every cell in the grid.

For each land cell, it starts with a perimeter contribution of `4`.

Then, for each neighboring land cell, the shared side is not part of the external perimeter.

A simple way to calculate the perimeter is:

1. Iterate through each row and column.
2. When a land cell is found, add `4` to the perimeter.
3. If the cell above is also land, subtract `2`.
4. If the cell to the left is also land, subtract `2`.
5. Return the final perimeter.

Only checking the top and left neighbors avoids counting the same shared side twice.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* Python 3.4.3
* All files must end with a new line
* The first line of all Python files must be:

```python id="nov5gt"
#!/usr/bin/python3
```

* Code must follow PEP 8 style
* No module imports are allowed
* All modules and functions must be documented
* All files must be executable

## Files

| File                    | Description                                                     |
| ----------------------- | --------------------------------------------------------------- |
| `0-island_perimeter.py` | Contains the implementation of the `island_perimeter` function. |
| `0-main.py`             | Example test file.                                              |

## Usage

Clone the repository and move into the project directory:

```bash id="ei5b72"
git clone <repository_url>
cd holbertonschool-interview/island_perimeter
```

Make the files executable if needed:

```bash id="qr9zh7"
chmod +x 0-island_perimeter.py 0-main.py
```

Run the test file:

```bash id="mt5q6u"
./0-main.py
```

Example output:

```text id="ii88ac"
12
```

## Function Prototype

```python id="nj670p"
def island_perimeter(grid):
```

## Return Value

The function returns an integer:

* the perimeter of the island
* `0` if there is no land in the grid

## Algorithm Complexity

Let:

* `h` be the height of the grid
* `w` be the width of the grid

The function checks each cell once.

* Time complexity: `O(h * w)`
* Space complexity: `O(1)`

The calculation is done directly while scanning the grid, without using additional data structures.

## Learning Objectives

This project helps practice:

* 2D grid traversal
* perimeter calculation
* neighbor checking
* algorithmic reasoning
* edge case handling
* Python implementation without imports
* writing documented and executable scripts
* technical interview preparation

## Author

Pierre-Yves
