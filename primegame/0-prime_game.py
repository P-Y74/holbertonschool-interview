#!/usr/bin/python3
"""
Prime Game module.
"""


def isWinner(x, nums):
    """
    Determine the player who wins the most rounds of the Prime Game.

    Args:
        x (int): Number of rounds.
        nums (list): List containing the value of n for each round.

    Returns:
        str: "Maria" or "Ben" depending on who wins the most rounds,
        or None if the winner cannot be determined.
    """
    if x <= 0 or not nums:
        return None

    max_n = max(nums)

    if max_n < 2:
        return "Ben" if x > 0 else None

    primes = [True] * (max_n + 1)
    primes[0] = False
    primes[1] = False

    p = 2
    while p * p <= max_n:
        if primes[p]:
            multiple = p * p
            while multiple <= max_n:
                primes[multiple] = False
                multiple += p
        p += 1

    prime_count = [0] * (max_n + 1)
    count = 0

    for i in range(max_n + 1):
        if primes[i]:
            count += 1
        prime_count[i] = count

    maria = 0
    ben = 0

    for n in nums[:x]:
        if n < 2:
            ben += 1
        elif prime_count[n] % 2 == 1:
            maria += 1
        else:
            ben += 1

    if maria > ben:
        return "Maria"

    if ben > maria:
        return "Ben"

    return None
