#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * match_words - checks if all words match starting at a given position
 * @s: pointer to the current position in the string
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 *
 * Return: 1 if all words are matched exactly once, otherwise 0
 */
int match_words(char const *s, char const **words,
				int nb_words, int word_len)
{
	int *used;
	int i, j;
	int found;

	used = malloc(sizeof(int) * nb_words);
	if (used == NULL)
		return (0);

	for (i = 0; i < nb_words; i++)
		used[i] = 0;

	for (i = 0; i < nb_words; i++)
	{
		found = 0;

		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
				strncmp(s + (i * word_len), words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}

		if (!found)
		{
			free(used);
			return (0);
		}
	}

	free(used);
	return (1);
}

/**
 * find_substring - finds substrings made from all given words
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of words
 * @n: address where the number of results is stored
 *
 * Return: allocated array of matching indexes, or NULL if none are found
 */
int *find_substring(char const *s, char const **words,
					int nb_words, int *n)
{
	int word_len;
	int total_len;
	int str_len;
	int *indices;
	int i;

	*n = 0;

	if (s == NULL || words == NULL || nb_words <= 0)
		return (NULL);

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	str_len = strlen(s);

	if (str_len < total_len)
		return (NULL);

	indices = malloc(sizeof(int) * (str_len - total_len + 1));
	if (indices == NULL)
		return (NULL);

	for (i = 0; i <= str_len - total_len; i++)
	{
		if (match_words(s + i, words, nb_words, word_len))
		{
			indices[*n] = i;
			(*n)++;
		}
	}

	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}

	return (indices);
}
