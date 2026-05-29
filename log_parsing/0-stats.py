#!/usr/bin/python3
"""
Reads log lines from standard input and computes metrics.

The script tracks:
- Total file size
- Number of occurrences of each valid HTTP status code

Statistics are printed every 10 processed lines and on
keyboard interruption (CTRL + C).
"""

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


def main():
    """
    Process log entries from standard input.

    Reads each log line, extracts the status code and file size,
    updates the accumulated metrics, and prints statistics every
    10 processed lines. If a keyboard interruption occurs,
    current statistics are printed before exiting.
    """
    global total_size
    global line_count

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

    if line_count > 0 and line_count % 10 != 0:
        print_stats()


def print_stats():
    """
    Print the accumulated log statistics.

    Displays the total file size and the number of
    occurrences for each valid HTTP status code.
    Only status codes with a count greater than zero
    are printed.
    """
    print(f"File size: {total_size}")

    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


if __name__ == "__main__":
    main()
