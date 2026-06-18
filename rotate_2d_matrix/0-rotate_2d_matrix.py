#!/usr/bin/python3
"""
Rotate 2D matrix module.
"""


def rotate_2d_matrix(matrix):
    """
    Rotate an n x n 2D matrix 90 degrees clockwise in-place.

    Args:
        matrix (list): Square 2D matrix to rotate.

    Return:
        None
    """
    size = len(matrix)

    for row in range(size):
        for col in range(row + 1, size):
            matrix[row][col], matrix[col][row] = \
                matrix[col][row], matrix[row][col]

    for row in range(size):
        matrix[row].reverse()
