# Log Parsing

## Description

This project focuses on parsing logs from standard input and computing basic metrics in real time.

The script reads lines one by one, extracts useful information from valid log entries, and prints statistics after every 10 processed lines or when interrupted with `CTRL + C`.

This exercise is useful for practicing input handling, string parsing, dictionaries, counters, and real-time data processing in Python.

## Problem Statement

Write a script that reads `stdin` line by line and computes metrics based on the following input format:

```text id="9t2qpl"
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

If a line does not match the expected format, it must be skipped.

The script must print the statistics:

* after every 10 valid lines
* when a keyboard interruption occurs using `CTRL + C`

## Metrics

The script must display:

1. The total file size:

```text id="mm52aq"
File size: <total size>
```

2. The number of lines for each valid status code.

Valid status codes are:

```text id="3wb75h"
200, 301, 400, 401, 403, 404, 405, 500
```

Status codes must be printed in ascending order.

A status code should only be printed if it appears at least once.

## Example

Example command:

```bash id="04qn11"
./0-generator.py | ./0-stats.py
```

Example output:

```text id="l62f1f"
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3
```

If the script is interrupted with `CTRL + C`, it must print the statistics collected so far before stopping.

## Approach

The script processes input line by line from `sys.stdin`.

For each valid line:

1. Extract the status code and file size.
2. Add the file size to the total.
3. Count the status code if it is one of the expected values.
4. Print the current statistics every 10 valid lines.

The script also handles `KeyboardInterrupt` to make sure the statistics are printed before the program exits.

The code must not execute when imported, which means the main execution logic should be protected with:

```python id="8h8a2y"
if __name__ == "__main__":
```

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* Python 3.4.3
* All files must end with a new line
* The first line of all Python files must be:

```python id="w84go8"
#!/usr/bin/python3
```

* Code must follow PEP 8 style
* All files must be executable
* File length may be tested using `wc`
* Code must not execute when imported

## Files

| File             | Description                                                             |
| ---------------- | ----------------------------------------------------------------------- |
| `0-stats.py`     | Python script that reads logs from standard input and computes metrics. |
| `0-generator.py` | Helper script used to generate random log entries for testing.          |

## Usage

Clone the repository and move into the project directory:

```bash id="a6xrrm"
git clone <repository_url>
cd holbertonschool-interview/log_parsing
```

Make sure the scripts are executable:

```bash id="4zuh7p"
chmod +x 0-generator.py 0-stats.py
```

Run the parser with generated logs:

```bash id="c6brcs"
./0-generator.py | ./0-stats.py
```

You can also test the parser manually:

```bash id="mjm18j"
echo '127.0.0.1 - [2024-01-01] "GET /projects/260 HTTP/1.1" 200 1024' | ./0-stats.py
```

Expected output:

```text id="2nnjsx"
File size: 1024
200: 1
```

## Algorithm Complexity

Let `n` be the number of input lines.

* Time complexity: `O(n)`
* Space complexity: `O(1)`

The space remains constant because only the total file size and a fixed set of status code counters are stored.

## Learning Objectives

This project helps practice:

* reading from standard input
* parsing structured log lines
* validating input format
* using dictionaries for counters
* handling keyboard interruptions
* writing executable Python scripts
* respecting PEP 8 style requirements
* processing streaming data in real time

## Author

Pierre-Yves
