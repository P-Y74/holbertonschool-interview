# lockboxes

## Description

This project focuses on solving a classic algorithmic problem involving **graph traversal** and **state exploration**.

Given a set of locked boxes, each containing keys to other boxes, the objective is to determine whether all boxes can be opened starting from the first one.

## Educational Context

This project was completed as part of the Holberton School interview preparation curriculum.

It represents a common problem used in technical interviews to evaluate problem-solving skills and understanding of traversal algorithms.

## Learning Objectives

By completing this project, the following concepts were practiced:

- graph traversal (DFS / BFS mindset)
- working with lists of lists
- tracking visited nodes
- avoiding infinite loops
- algorithmic thinking and state exploration

## Problem Statement

You have `n` locked boxes numbered from `0` to `n - 1`.

Each box may contain keys to other boxes.

- A key with value `x` opens box `x`
- The first box (`boxes[0]`) is already unlocked
- Some keys may not correspond to any box

## Task

### `0-lockboxes.py`

**Prototype:**
```python id="q8t2na"
def canUnlockAll(boxes):
````

**Description:**

* Determines if all boxes can be opened
* Starts from box `0`
* Uses keys found in boxes to unlock others
* Returns:

  * `True` → if all boxes can be opened
  * `False` → otherwise

## Files Included

* `0-lockboxes.py` → main algorithm
* `main_0.py` → test file (for local testing)

## Requirements

* Python 3.4.3
* Ubuntu 14.04 LTS
* PEP 8 style (v1.7)
* All files must be executable
* First line must be:

```bash
#!/usr/bin/python3
```

* Code must be documented

## Usage

Example:

```bash id="zq7m1w"
./main_0.py
```

## Key Concepts

### Graph Traversal

Each box represents a node, and each key represents a connection.

This problem is equivalent to checking if all nodes in a graph are reachable from node `0`.

### Visited Tracking

To avoid loops and redundant work, visited boxes must be tracked.

### DFS / BFS Approach

Two valid approaches:

* Depth-First Search (DFS)
* Breadth-First Search (BFS)

## Example

```python id="l0h8qs"
boxes = [[1], [2], [3], []]
```

Result → `True` (all boxes can be opened)

```python id="l2n4df"
boxes = [[1, 3], [3, 0, 1], [2], [0]]
```

Result → `False` (box 2 is never reached)

## Learning Outcomes

* understanding of traversal algorithms
* ability to model problems as graphs
* efficient state tracking
* solving reachability problems

## Complexity

* Time: O(n + k)

  * n = number of boxes
  * k = number of keys
* Space: O(n)

## Project Status

This project is part of an interview preparation repository and may be extended with:

* cycle detection problems
* graph shortest path algorithms
* advanced traversal techniques

## Author

Pierre-Yves
