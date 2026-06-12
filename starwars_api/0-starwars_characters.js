#!/usr/bin/node
/**
 * Prints all characters of a Star Wars movie.
 *
 * The script fetches a movie from the Star Wars API using the movie ID
 * passed as the first argument, then prints each character name in the
 * same order as listed by the API.
 */

const request = require('request');

const movieId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(filmUrl, (error, response, body) => {
  if (error) return;

  const film = JSON.parse(body);
  const characters = film.characters;

  printCharacters(characters, 0);
});

/**
 * Recursively prints character names in order.
 *
 * @param {string[]} characters - List of character API URLs.
 * @param {number} index - Current character index to fetch.
 */
function printCharacters (characters, index) {
  if (index >= characters.length) {
    return;
  }

  request(characters[index], (error, response, body) => {
    if (error) return;

    const character = JSON.parse(body);

    console.log(character.name);
    printCharacters(characters, index + 1);
  });
}
