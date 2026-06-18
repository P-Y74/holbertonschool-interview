#include <stdlib.h>

/**
 * is_digit_string - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int is_digit_string(char *s)
{
	int i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}
