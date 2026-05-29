#!/usr/bin/python3

import sys

total_size = 0

status_counts = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

line_count = 0


def print_stats():
    print(f"File size: {total_size}")

    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()
        try:
            status_code = parts[-2]
            size = int(parts[-1])
        except (IndexError, ValueError):
            continue

        total_size += size

        if status_code in status_counts:
            status_counts[status_code] += 1

        if line_count % 10 == 0:
            print_stats()
except KeyboardInterrupt:
    print_stats()
    raise
