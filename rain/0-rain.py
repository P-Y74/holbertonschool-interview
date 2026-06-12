#!/usr/bin/python3
"""
Rainwater trapping module.
"""


def rain(walls):
    """
    Calculate how much rainwater can be retained.

    Args:
        walls (list): List of non-negative integers representing wall heights.

    Returns:
        int: Total amount of retained rainwater.
    """
    if not walls:
        return 0

    total = 0
    size = len(walls)

    for i in range(size):
        left_max = max(walls[:i + 1])
        right_max = max(walls[i:])

        water = min(left_max, right_max) - walls[i]

        if water > 0:
            total += water

    return total
