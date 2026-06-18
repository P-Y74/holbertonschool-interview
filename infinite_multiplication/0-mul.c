#include "holberton.h"
#include <stdlib.h>



/**
 * print_error - prints Error and exits with status 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * init_array - initializes an integer array with zeros
 * @array: array to initialize
 * @size: size of the array
 */
void init_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
}

/**
 * multiply - multiplies two numeric strings
 * @num1: first number as a string
 * @num2: second number as a string
 * @result: array used to store the result digits
 * @len1: length of num1
 * @len2: length of num2
 */
void multiply(char *num1, char *num2, int *result, int len1, int len2)
{
	int i;
	int j;
	int digit1;
	int digit2;
	int product;

	i = len1 - 1;
	while (i >= 0)
	{
		digit1 = num1[i] - '0';
		j = len2 - 1;

		while (j >= 0)
		{
			digit2 = num2[j] - '0';
			product = digit1 * digit2;

			result[i + j + 1] += product;
			result[i + j] += result[i + j + 1] / 10;
			result[i + j + 1] %= 10;

			j--;
		}
		i--;
	}
}

/**
 * print_result - prints the multiplication result
 * @result: array containing result digits
 * @size: size of the result array
 */
void print_result(int *result, int size)
{
	int i;

	i = 0;

	while (i < size - 1 && result[i] == 0)
		i++;

	while (i < size)
	{
		_putchar(result[i] + '0');
		i++;
	}

	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *num1;
	char *num2;
	int len1;
	int len2;
	int size;
	int *result;

	if (argc != 3)
		print_error();

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit_string(num1) || !is_digit_string(num2))
		print_error();

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	size = len1 + len2;

	result = malloc(sizeof(int) * size);
	if (result == NULL)
		print_error();

	init_array(result, size);
	multiply(num1, num2, result, len1, len2);
	print_result(result, size);

	free(result);

	return (0);
}
