# Rain

## Description

This project focuses on solving the rainwater trapping problem.

Given a list of non-negative integers representing walls of width `1`, the goal is to calculate how much water can be retained after it rains.

This is a classic algorithmic problem that requires understanding how boundaries on the left and right side of each position affect the amount of trapped water.

## Problem Statement

Write a function that calculates the total amount of rainwater retained between walls.

Prototype:

```python id="0dtxf8"
def rain(walls)
```

Where:

* `walls` is a list of non-negative integers
* each integer represents the height of a wall
* each wall has a width of `1`

The function must return:

* the total amount of retained rainwater as an integer
* `0` if the list is empty

The ends of the list are not considered walls that can retain water outside the array.

## Example

Given the following walls:

```python id="xvl9po"
walls = [0, 1, 0, 2, 0, 3, 0, 4]
```

The retained water is:

```text id="4sjper"
6
```

Another example:

```python id="mm21w3"
walls = [2, 0, 0, 4, 0, 0, 1, 0]
```

The retained water is:

```text id="zshuhe"
6
```

## Approach

For each position, the amount of water that can be trapped depends on the tallest wall to its left and the tallest wall to its right.

The water above a position is calculated as:

```text id="4sm5ia"
min(left_max, right_max) - current_height
```

If the result is negative or zero, no water is retained at that position.

A common efficient approach is to use two pointers:

1. Start with one pointer at the beginning of the list and one at the end.
2. Track the maximum wall seen from the left.
3. Track the maximum wall seen from the right.
4. Move the pointer with the smaller maximum height.
5. Add trapped water when the current wall is lower than the known boundary.

This avoids checking the full left and right side for every index.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* Python 3.4.3
* All files must end with a new line
* The first line of all Python files must be:

```python id="3e9h0i"
#!/usr/bin/python3
```

* Code must follow PEP 8 style
* No module imports are allowed
* All modules and functions must be documented
* All files must be executable

## Files

| File        | Description                                         |
| ----------- | --------------------------------------------------- |
| `0-rain.py` | Contains the implementation of the `rain` function. |
| `0_main.py` | Example test file.                                  |

## Usage

Clone the repository and move into the project directory:

```bash id="a0l29v"
git clone <repository_url>
cd holbertonschool-interview/rain
```

Make the files executable if needed:

```bash id="n7rtq9"
chmod +x 0-rain.py 0_main.py
```

Run the test file:

```bash id="yfgs97"
./0_main.py
```

Example output:

```text id="su8cxp"
6
6
```

## Function Prototype

```python id="k2nj87"
def rain(walls)
```

## Return Value

The function returns an integer:

* total number of square units of rainwater retained
* `0` if the list is empty or if no water can be retained

## Algorithm Complexity

Let `n` be the number of walls.

Using the two-pointer approach:

* Time complexity: `O(n)`
* Space complexity: `O(1)`

The function processes the list in a single pass and does not use additional data structures.

## Learning Objectives

This project helps practice:

* algorithmic problem solving
* two-pointer techniques
* list traversal
* boundary tracking
* optimization reasoning
* edge case handling
* Python implementation without imports
* technical interview preparation

## Author

Pierre-Yves
