# Making Change

## Description

This project focuses on solving the coin change problem.

Given a list of coin denominations and a target total, the goal is to determine the fewest number of coins needed to reach exactly that total.

This is a classic optimization problem often solved using dynamic programming.

## Problem Statement

Write a function that determines the fewest number of coins needed to meet a given total.

Prototype:

```python
def makeChange(coins, total)
```

Where:

* `coins` is a list of coin values
* `total` is the amount to reach
* each coin value is an integer greater than `0`
* there is an infinite number of each coin denomination

The function must return:

* the fewest number of coins needed to meet `total`
* `0` if `total` is `0` or less
* `-1` if the total cannot be reached with the available coins

## Example

Test file:

```python
#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))
print(makeChange([1256, 54, 48, 16, 102], 1453))
```

Expected output:

```text
7
-1
```

For the first example:

```text
coins = [1, 2, 25]
total = 37
```

The minimum number of coins is `7`:

```text
25 + 2 + 2 + 2 + 2 + 2 + 2 = 37
```

## Approach

A greedy approach does not always guarantee the optimal solution for every set of coin denominations.

A safer approach is to use dynamic programming.

The idea is to build a table where each index represents an amount from `0` to `total`.

For each amount, the algorithm stores the fewest number of coins needed to reach that amount.

General logic:

1. If `total` is less than or equal to `0`, return `0`.
2. Create a list to store the minimum number of coins for each amount.
3. Initialize the value for amount `0` as `0`.
4. For each coin, update the minimum number of coins needed for all reachable amounts.
5. Return the value stored for `total`.
6. If `total` cannot be reached, return `-1`.

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
* Runtime efficiency will be evaluated

## Files

| File                 | Description                                               |
| -------------------- | --------------------------------------------------------- |
| `0-making_change.py` | Contains the implementation of the `makeChange` function. |
| `0-main.py`          | Example test file.                                        |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/making_change
```

Make the files executable if needed:

```bash
chmod +x 0-making_change.py 0-main.py
```

Run the test file:

```bash
./0-main.py
```

Example output:

```text
7
-1
```

## Function Prototype

```python
def makeChange(coins, total)
```

## Return Value

The function returns an integer:

* minimum number of coins needed to reach `total`
* `0` if `total` is less than or equal to `0`
* `-1` if the total cannot be reached

## Algorithm Complexity

Let:

* `n` be the target total
* `m` be the number of coin denominations

Using dynamic programming:

* Time complexity: `O(n * m)`
* Space complexity: `O(n)`

The algorithm stores the best result for each amount from `0` to `total`.

## Learning Objectives

This project helps practice:

* dynamic programming
* optimization problems
* coin change algorithms
* list manipulation in Python
* edge case handling
* avoiding unreliable greedy solutions
* runtime complexity reasoning
* technical interview preparation

## Author

Pierre-Yves
