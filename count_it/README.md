# Count It!

## Description

This project focuses on using recursion, API requests, and text parsing in Python.

The goal is to query the Reddit API, retrieve all hot article titles from a given subreddit, count how many times specific keywords appear, and print the results sorted by frequency.

The function must handle pagination recursively and must not follow redirects for invalid subreddits.

## Problem Statement

Write a recursive function that queries the Reddit API, parses the titles of all hot articles, and prints a sorted count of given keywords.

Prototype:

```python
def count_words(subreddit, word_list)
```

Where:

* `subreddit` is the subreddit to query
* `word_list` is a list of keywords to count

The function must:

* count keywords case-insensitively
* count duplicate keywords together
* count each occurrence of a keyword, not only each title
* skip words with no matches
* print words in lowercase
* print nothing if the subreddit is invalid or if no posts match
* use recursion to handle pagination

## Keyword Matching Rules

Keyword matching is case-insensitive.

For example:

```text
JavA
java
JAVA
```

are all counted as:

```text
java
```

However, words must be delimited by spaces.

This means:

```text
javascript
```

counts as `javascript`, but not as `java`.

Also, punctuation or symbols attached to a word should not count as a valid match.

Examples that should not count as `java`:

```text
java.
java!
java_
```

## Sorting Rules

The final output must be sorted:

1. By count in descending order
2. Alphabetically in ascending order when counts are equal

Example:

```text
java: 27
javascript: 20
python: 17
react: 17
scala: 4
```

In this example, `python` and `react` both have the same count, so they are sorted alphabetically.

## Example

Test file:

```python
#!/usr/bin/python3
"""
0-main
"""
import sys

if __name__ == '__main__':
    count_words = __import__('0-count').count_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        result = count_words(sys.argv[1], [x for x in sys.argv[2].split()])
```

Run the script:

```bash
python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
```

Example output:

```text
java: 27
javascript: 20
python: 17
react: 17
scala: 4
```

Duplicate keywords are combined:

```bash
python3 0-main.py programming 'JavA java'
```

Example output:

```text
java: 54
```

Invalid subreddit:

```bash
python3 0-main.py not_a_valid_subreddit 'python java'
```

Expected output:

```text
```

Nothing is printed.

## Approach

The function queries Reddit's hot posts endpoint for the given subreddit.

Because Reddit returns results in pages, the function must use the `after` value from the API response to request the next page.

The general logic is:

1. Normalize the keyword list to lowercase.
2. Build a counter for all requested words.
3. Send a request to the Reddit API.
4. Parse each post title.
5. Split titles into words.
6. Count exact keyword matches.
7. Recursively request the next page using the `after` parameter.
8. Once there are no more pages, sort and print the final counts.

Redirects must be disabled to correctly handle invalid subreddits.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* Python 3.4.3
* All files must end with a new line
* The first line of all Python files must be:

```python
#!/usr/bin/python3
```

* Libraries must be imported in alphabetical order
* Code must follow PEP 8 style
* All files must be executable
* File length may be tested using `wc`
* All modules must be documented
* The `Requests` module must be used
* The function must use recursion

## Files

| File         | Description                                    |
| ------------ | ---------------------------------------------- |
| `0-count.py` | Contains the recursive `count_words` function. |
| `0-main.py`  | Example test file used to call the function.   |

## Usage

Clone the repository and move into the project directory:

```bash
git clone <repository_url>
cd holbertonschool-interview/count_it
```

Make the files executable if needed:

```bash
chmod +x 0-count.py 0-main.py
```

Run the program:

```bash
python3 0-main.py programming 'python java javascript'
```

## Function Prototype

```python
def count_words(subreddit, word_list)
```

The prototype may include additional parameters for recursion, counters, or pagination, but the function must still work when called with only:

```python
count_words(subreddit, word_list)
```

## Return Value

The function does not return a value.

It prints the final keyword counts directly to standard output.

If no valid matches are found, nothing is printed.

## Algorithm Complexity

Let:

* `p` be the number of posts processed
* `w` be the number of words across all titles
* `k` be the number of keywords

The approximate complexity is:

* Time complexity: `O(w + k log k)`
* Space complexity: `O(k)`

The keyword counter stores only the requested words and their counts.

## Learning Objectives

This project helps practice:

* recursive API pagination
* HTTP requests with the `requests` module
* Reddit API usage
* JSON parsing
* text normalization
* keyword counting
* sorting with multiple criteria
* handling invalid API responses
* writing PEP 8 compliant Python code

## Author

Pierre-Yves
