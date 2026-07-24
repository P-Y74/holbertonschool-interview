#include "sort.h"
#include <stdlib.h>

/**
 * get_max - finds the maximum value in an array
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum value in the array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort_digit - sorts an array according to a specific digit
 * @array: array to sort
 * @buffer: temporary buffer
 * @size: size of the array
 * @exp: current digit position
 */
void counting_sort_digit(int *array, int *buffer, size_t size, int exp)
{
	int count[10] = {0};
	size_t i;
	int digit;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	for (digit = 1; digit < 10; digit++)
		count[digit] += count[digit - 1];

	i = size;
	while (i > 0)
	{
		i--;
		digit = (array[i] / exp) % 10;
		buffer[count[digit] - 1] = array[i];
		count[digit]--;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - sorts an array of integers using LSD radix sort
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_digit(array, buffer, size, exp);
		print_array(array, size);
	}

	free(buffer);
}
