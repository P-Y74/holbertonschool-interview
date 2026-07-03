# Star Wars API

## Description

This project focuses on using an external API from a Node.js script.

The goal is to retrieve and print all characters from a specific Star Wars movie by using the Star Wars API.

The script takes a movie ID as a command-line argument, fetches the corresponding movie data, then prints each character name in the same order as listed by the API.

## Problem Statement

Write a script that prints all characters of a Star Wars movie.

Usage:

```bash id="6byz8m"
./0-starwars_characters.js <movie_id>
```

Where `<movie_id>` is the ID of the Star Wars movie.

Example:

```bash id="grji0n"
./0-starwars_characters.js 3
```

The script must:

* use the Star Wars API
* use the `request` module
* display one character name per line
* preserve the same order as the `characters` list from the `/films/` endpoint

## Example

Command:

```bash id="lvseg5"
./0-starwars_characters.js 3
```

Output:

```text id="c6vmo8"
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

## Approach

The script works in two main steps.

First, it sends a request to the Star Wars API film endpoint using the movie ID provided as an argument.

Then, it retrieves the list of character URLs from the movie response and sends requests to each character endpoint.

The names are printed in the same order as the character URLs appear in the movie data.

Because API requests are asynchronous in Node.js, the script must handle the order carefully to avoid printing characters in the wrong sequence.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Ubuntu 14.04 LTS
* Node.js 10.14.x
* All files must end with a new line
* The first line of the script must be:

```javascript id="xeu9y9"
#!/usr/bin/node
```

* Code must be semistandard compliant
* Standard style + semicolons
* AirBnB style as reference
* All files must be executable
* File length may be tested using `wc`
* The use of `var` is not allowed
* The `request` module must be used

## Installation

Install Node.js 10:

```bash id="5ogp8n"
curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
sudo apt-get install -y nodejs
```

Install `semistandard`:

```bash id="24bzcw"
sudo npm install semistandard --global
```

Install the `request` module:

```bash id="95tmsi"
sudo npm install request --global
export NODE_PATH=/usr/lib/node_modules
```

## Files

| File                       | Description                                                       |
| -------------------------- | ----------------------------------------------------------------- |
| `0-starwars_characters.js` | Node.js script that prints all characters from a Star Wars movie. |

## Usage

Clone the repository and move into the project directory:

```bash id="kkmh3a"
git clone <repository_url>
cd holbertonschool-interview/starwars_api
```

Make the file executable if needed:

```bash id="fa4kq1"
chmod +x 0-starwars_characters.js
```

Run the script with a movie ID:

```bash id="e8tytk"
./0-starwars_characters.js 3
```

## Code Style

Check the script with `semistandard`:

```bash id="mgpesv"
semistandard 0-starwars_characters.js
```

## Learning Objectives

This project helps practice:

* using Node.js scripts
* working with command-line arguments
* sending HTTP requests
* consuming an external API
* handling asynchronous JavaScript
* preserving output order during async operations
* parsing JSON responses
* following semistandard style rules

## Author

Pierre-Yves
