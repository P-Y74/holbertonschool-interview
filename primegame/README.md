# Prime Game

## Description

This project focuses on solving a competitive game based on prime numbers.

Maria and Ben play several rounds. For each round, they are given a set of consecutive integers from `1` to `n`.

Players take turns choosing a prime number from the set. When a prime number is chosen, that number and all of its multiples are removed from the set.

The player who cannot make a move loses the round.

Maria always plays first, and both players play optimally.

## Problem Statement

Write a function that determines who wins the most rounds.

Prototype:

```python
def isWinner(x, nums)
```

Where:

* `x` is the number of rounds
* `nums` is a list of values of `n`
* each `n` represents a game using numbers from `1` to `n`

The function must return:

* `"Maria"` if Maria wins the most rounds
* `"Ben"` if Ben wins the most rounds
* `None` if the winner cannot be determined

## Game Rules

For each round:

1. The set starts with numbers from `1` to `n`.
2. Maria plays first.
3. A player chooses a prime number.
4. The chosen prime and all of its multiples are removed.
5. Players alternate turns.
6. The player who cannot choose a prime loses.

Example with `n = 4`:

```text
Initial set: 1, 2, 3, 4

Maria chooses 2
Remove 2 and 4
Remaining: 1, 3

Ben chooses 3
Remove 3
Remaining: 1

Maria cannot move
Ben wins
```

## Example

Given:

```python
x = 3
nums = [4, 5, 1]
```

Round 1, `n = 4`:

```text
Maria chooses 2
Ben chooses 3
Ben wins
```

Round 2, `n = 5`:

```text
Maria chooses 2
Ben chooses 3
Maria chooses 5
Maria wins
```

Round 3, `n = 1`:

```text
No prime numbers are available
Ben wins
```

Final result:

```text
Ben has the most wins
```

## Test File

```python
#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner

print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))
```

Expected output:

```text
Winner: Ben
```

## Approach

The key idea is to count how many prime numbers are available from `1` to `n`.

Each valid move removes one chosen prime from the set.
The number of moves in a round depends on the number of prime numbers up to `n`.

If the number of available primes is odd:

```text
Maria wins
```

If the number of available primes is even:

```text
Ben wins
```

This is because Maria always starts first.

To solve the problem efficiently:

1. Find the maximum value in `nums`.
2. Generate prime numbers up to that maximum.
3. Count how many primes exist up to each value of `n`.
4. For each round, determine the winner based on whether the prime count is odd or even.
5. Return the player with the most wins.

A Sieve of Eratosthenes can be used to precompute prime numbers efficiently.

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
* No package imports are allowed
* `n` and `x` will not be larger than `10000`

## Files

| File              | Description                                             |
| ----------------- | ------------------------------------------------------- |
| `0-prime_game.py` | Contains the implementation of the `isWinner` function. |
| `main_0.py`       | Example test file.                                      |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/primegame
```

Make the files executable if needed:

```bash
chmod +x 0-prime_game.py main_0.py
```

Run the test file:

```bash
./main_0.py
```

Example output:

```text
Winner: Ben
```

## Function Prototype

```python
def isWinner(x, nums)
```

## Return Value

The function returns:

* `"Maria"` if Maria wins more rounds
* `"Ben"` if Ben wins more rounds
* `None` if both players win the same number of rounds or if the winner cannot be determined

## Algorithm Complexity

Let:

* `m` be the maximum value in `nums`
* `x` be the number of rounds

Using prime precomputation with the Sieve of Eratosthenes:

* Time complexity: `O(m log log m + x)`
* Space complexity: `O(m)`

The sieve is computed once and reused for all rounds.

## Learning Objectives

This project helps practice:

* prime number detection
* Sieve of Eratosthenes
* game theory basics
* turn-based logic
* precomputation
* optimization across multiple rounds
* Python list manipulation
* edge case handling
* technical interview preparation

## Author

Pierre-Yves
