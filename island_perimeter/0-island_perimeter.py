#!/usr/bin/python3
"""
Island perimeter module.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in a grid.

    Args:
        grid (list): Rectangular grid where 0 represents water
        and 1 represents land.

    Returns:
        int: Perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perimeter += 4

                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 2

                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2

    return perimeter
