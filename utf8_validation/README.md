# UTF-8 Validation

## Description

This project focuses on validating whether a given list of integers represents a valid UTF-8 encoding.

UTF-8 is a variable-length character encoding system where each character can be represented using 1 to 4 bytes.

The goal is to analyze each byte and determine whether the full data set follows the UTF-8 encoding rules.

## Resources

Recommended resources:

* UTF-8
* Characters, Symbols, and the Unicode Miracle

## Problem Statement

Write a method that determines if a given data set represents a valid UTF-8 encoding.

Prototype:

```python
def validUTF8(data)
```

The function must return:

* `True` if the data is a valid UTF-8 encoding
* `False` otherwise

The data set is represented by a list of integers.
Each integer represents one byte of data, so only the 8 least significant bits of each integer should be considered.

## UTF-8 Encoding Rules

A UTF-8 character can be from 1 to 4 bytes long.

The first byte determines how many bytes are used for the character:

| Byte pattern | Meaning                     |
| ------------ | --------------------------- |
| `0xxxxxxx`   | 1-byte character            |
| `110xxxxx`   | Start of a 2-byte character |
| `1110xxxx`   | Start of a 3-byte character |
| `11110xxx`   | Start of a 4-byte character |
| `10xxxxxx`   | Continuation byte           |

Continuation bytes must always start with `10`.

For example:

```text
110xxxxx 10xxxxxx
```

represents a valid 2-byte UTF-8 character.

## Example

Test file:

```python
data = [65]
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

data = [229, 65, 127, 256]
print(validUTF8(data))
```

Expected output:

```text
True
True
False
```

## Approach

The function reads the list of integers from left to right.

For each byte:

1. Keep only the 8 least significant bits.
2. Determine whether the byte starts a new UTF-8 character or continues a previous one.
3. Track how many continuation bytes are expected.
4. Validate that continuation bytes start with the `10` bit pattern.
5. Return `False` if an invalid pattern is found.
6. Return `True` only if all expected continuation bytes are correctly completed.

Example:

```text
[229, 65, 127, 256]
```

The byte `229` starts a multi-byte character, but the following byte does not correctly continue it.
Therefore, the data is invalid.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* Python 3.4.3
* All files must end with a new line
* The first line of all Python files must be:

```python
#!/usr/bin/python3
```

* Code must follow PEP 8 style
* All files must be executable

## Files

| File                 | Description                                              |
| -------------------- | -------------------------------------------------------- |
| `0-validate_utf8.py` | Contains the implementation of the `validUTF8` function. |
| `0-main.py`          | Example test file.                                       |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/utf8_validation
```

Make the files executable if needed:

```bash
chmod +x 0-main.py 0-validate_utf8.py
```

Run the test file:

```bash
./0-main.py
```

Example output:

```text
True
True
False
```

## Function Prototype

```python
def validUTF8(data)
```

## Return Value

The function returns a boolean:

* `True` if the data set is a valid UTF-8 encoding
* `False` otherwise

## Algorithm Complexity

Let `n` be the number of integers in the input list.

* Time complexity: `O(n)`
* Space complexity: `O(1)`

The function processes the data in a single pass and only stores a small counter for expected continuation bytes.

## Learning Objectives

This project helps practice:

* bitwise operations
* binary representation of bytes
* UTF-8 encoding rules
* input validation
* single-pass algorithms
* edge case handling
* Python implementation for technical interview problems

## Author

Pierre-Yves
