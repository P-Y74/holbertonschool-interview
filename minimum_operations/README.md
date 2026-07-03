# Minimum Operations

## Description

This project focuses on solving an algorithmic problem using only two available operations:

* **Copy All**
* **Paste**

Starting with a single character `H`, the goal is to determine the minimum number of operations required to obtain exactly `n` characters.

The challenge is to find an efficient strategy instead of simulating every possible sequence of operations.

## Problem Statement

Given a number `n`, write a function that calculates the fewest number of operations needed to result in exactly `n` `H` characters in a file.

Prototype:

```python
def minOperations(n)
```

The function must return:

* the minimum number of operations needed
* `0` if `n` cannot be achieved

## Example

For `n = 9`:

```text
H
Copy All
Paste        -> HH
Paste        -> HHH
Copy All
Paste        -> HHHHHH
Paste        -> HHHHHHHHH
```

Total number of operations: `6`

## Approach

The problem can be solved by breaking `n` down into factors.

Each time we copy the current number of characters and paste it multiple times, we are effectively multiplying the current amount of `H` characters.

To minimize the number of operations, the algorithm decomposes `n` into its smallest factors.
The sum of these factors gives the minimum number of operations required.

For example:

```text
n = 12
12 = 2 × 2 × 3

Minimum operations = 2 + 2 + 3 = 7
```

This corresponds to:

```text
H
Copy All + Paste        -> 2 H
Copy All + Paste        -> 4 H
Copy All + Paste + Paste -> 12 H
```

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
* Code must be documented

## Files

| File                 | Description                            |
| -------------------- | -------------------------------------- |
| `0-minoperations.py` | Contains the `minOperations` function. |
| `0-main.py`          | Test file used to check the function.  |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/minimum_operations
```

Run the test file:

```bash
./0-main.py
```

Example output:

```text
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
```

## Function Prototype

```python
def minOperations(n)
```

## Return Value

The function returns an integer:

* minimum number of operations if `n` is valid
* `0` if `n` is less than or equal to `1`

## Algorithm Complexity

Let `n` be the target number of characters.

* Time complexity: `O(sqrt(n))` in the typical factorization approach
* Space complexity: `O(1)`

## Learning Objectives

This project helps practice:

* algorithmic problem solving
* factorization logic
* optimization reasoning
* Python function implementation
* edge case handling
* technical interview preparation

## Author

Pierre-Yves
