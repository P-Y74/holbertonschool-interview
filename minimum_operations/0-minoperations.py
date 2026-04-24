#!/usr/bin/python3
"""
Module that provides a function to calculate the minimum number
of operations required to obtain exactly n 'H' characters in a text file.

Only two operations are allowed:
- Copy All
- Paste

The solution is based on prime factorization of n.
"""


def minOperations(n):
    """
    Calculate the minimum number of operations needed to get n 'H' characters.

    Starting with a single 'H', this function determines the fewest number of
    Copy All and Paste operations required to reach exactly n 'H' characters.

    The strategy relies on breaking n down into its prime factors.
    The sum of these factors represents the minimum number of operations.

    Args:
        n (int): The target number of 'H' characters.

    Returns:
        int: The minimum number of operations required.
             Returns 0 if n is less than or equal to 1.
    """

    if n <= 1:
        return 0

    operations = 0
    i = 2

    while n > 1:
        if n % i == 0:
            operations += i
            n //= i
        else:
            i += 1

    return operations
