#!/usr/bin/python3
"""
Pascal's Triangle module.
"""


def pascal_triangle(n):
    """
    Generate Pascal's Triangle with n rows.

    Args:
        n (int): Number of rows to generate.

    Returns:
        list: List of lists representing Pascal's Triangle.
    """
    triangle = []

    if n <= 0:
        return triangle

    for row in range(n):
        current = [1] * (row + 1)

        for col in range(1, row):
            current[col] = (
                triangle[row - 1][col - 1] +
                triangle[row - 1][col]
            )

        triangle.append(current)

    return triangle
