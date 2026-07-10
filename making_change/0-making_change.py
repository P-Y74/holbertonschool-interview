#!/usr/bin/python3
"""
Making change module.
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total.

    Args:
        coins (list): List of coin denominations.
        total (int): Target total amount.

    Returns:
        int: Fewest number of coins needed, 0 if total is 0 or less,
        or -1 if the total cannot be met.
    """
    if total <= 0:
        return 0

    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    if dp[total] == total + 1:
        return -1

    return dp[total]
