# Substring with Concatenated Words

## Description

This project focuses on finding all starting indexes in a string where a substring is made by concatenating a given list of words.

Each valid substring must contain every word from the list exactly once, without extra characters between them.

This exercise helps practice string scanning, substring comparison, dynamic memory allocation, and algorithmic reasoning in C.

## Problem Statement

Write a function that finds all possible substrings containing a list of words within a given string.

Prototype:

```c
int *find_substring(char const *s, char const **words, int nb_words, int *n);
```

Where:

* `s` is the string to scan
* `words` is the array of words that must appear in each valid substring
* `nb_words` is the number of words in the array
* `n` stores the number of indexes found

The function must return:

* an allocated array containing the starting indexes where valid substrings were found
* `NULL` if no valid substring is found

All words in `words` have the same length.

## Valid Substring Rule

A valid substring must be made of all words from `words`:

* each word must appear exactly once
* words may appear in any order
* there must be no extra characters between words
* all words have the same length

Example:

```text
s = "barfoothefoobarman"
words = ["foo", "bar"]
```

Valid substrings:

```text
"barfoo" starts at index 0
"foobar" starts at index 9
```

Result:

```text
[0, 9]
```

## Examples

Compilation:

```bash
gcc -Wall -Wextra -Werror -pedantic main.c substring.c
```

Execution:

```bash
./a.out barfoothefoobarman foo bar
```

Output:

```text
Indices -> [0, 9]
```

Another example:

```bash
./a.out wordgoodgoodgoodbestword word good best word
```

Output:

```text
Indices -> []
```

Example with a match:

```bash
./a.out wordgoodgoodgoodbestword word good best good
```

Output:

```text
Indices -> [8]
```

## Approach

The function scans the string from left to right.

For each possible starting index:

1. Calculate the total length needed for a valid concatenation.
2. Extract each word-sized part of the substring.
3. Check whether each extracted part exists in the `words` array.
4. Make sure each word is used only once.
5. If all words are found exactly once, store the starting index.
6. Continue scanning until the end of the string.

Because the words can appear in any order, the algorithm must track which words have already been matched for each candidate substring.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* GCC 4.8.4
* Compilation flags:

```bash
-Wall -Werror -Wextra -pedantic
```

* All files must end with a new line
* Code must follow Betty style
* No global variables allowed
* No more than 5 functions per file
* Example `main.c` files are only for testing
* All function prototypes must be included in `substring.h`
* Header files must be include guarded

## Files

| File          | Description                                      |
| ------------- | ------------------------------------------------ |
| `substring.c` | Contains the implementation of `find_substring`. |
| `substring.h` | Header file containing function prototypes.      |
| `main.c`      | Example test file.                               |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/substring
```

Compile the files:

```bash
gcc -Wall -Wextra -Werror -pedantic main.c substring.c
```

Run the program:

```bash
./a.out barfoothefoobarman foo bar
```

Example output:

```text
Indices -> [0, 9]
```

## Function Prototype

```c
int *find_substring(char const *s, char const **words, int nb_words, int *n);
```

## Return Value

The function returns:

* an allocated array of indexes where valid substrings start
* `NULL` if no valid substring is found

The value pointed to by `n` must contain the number of indexes found.

If an allocated array is returned, it should be freed by the caller when it is no longer needed.

## Algorithm Complexity

Let:

* `s_len` be the length of the string
* `w_count` be the number of words
* `w_len` be the length of each word

A straightforward implementation checks each possible starting position and compares word-sized chunks against the word list.

Approximate complexity:

* Time complexity: `O(s_len * w_count * w_len)`
* Space complexity: `O(w_count + r)`

Where `r` is the number of matching indexes stored in the result array.

## Learning Objectives

This project helps practice:

* string scanning in C
* substring comparison
* array manipulation
* dynamic memory allocation
* tracking matched words
* handling duplicate words
* validating full concatenations
* pointer manipulation
* strict C compilation requirements
* Betty-compliant C code

## Author

Pierre-Yves
