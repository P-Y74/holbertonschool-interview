#!/usr/bin/python3
"""
Count keywords in hot Reddit posts recursively.
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively query Reddit hot posts and count keyword occurrences.
    """
    if counts is None:
        counts = {}

        for word in word_list:
            word = word.lower()
            counts[word] = counts.get(word, 0)

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "holberton-count-it"}
    params = {"limit": 100}

    if after:
        params["after"] = after

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json().get("data")
    if data is None:
        return

    children = data.get("children", [])

    for post in children:
        title = post.get("data", {}).get("title", "").lower()
        words = title.split()

        for word in words:
            if word in counts:
                counts[word] += 1

    after = data.get("after")

    if after:
        return count_words(subreddit, word_list, after, counts)

    results = sorted(
        [(word, count) for word, count in counts.items() if count > 0],
        key=lambda item: (-item[1], item[0])
    )

    for word, count in results:
        print("{}: {}".format(word, count))
