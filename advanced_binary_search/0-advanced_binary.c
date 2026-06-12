#include "search_algos.h"
#include <stdlib.h>

/**
 * print_array - prints the current subarray being searched
 * @array: pointer to the first element of the array
 * @left: left index of the subarray
 * @right: right index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search - recursively searches for the first occurrence of a value
 * @array: pointer to the first element of the array
 * @left: left index of the current search range
 * @right: right index of the current search range
 * @value: value to search for
 *
 * Return: index of the first occurrence of value, or -1 if not found
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value && (mid == 0 || array[mid - 1] != value))
		return ((int)mid);

	if (array[mid] >= value)
	{
		if (mid == 0)
			return (-1);
		return (binary_search(array, left, mid - 1, value));
	}

	return (binary_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - searches for the first occurrence of a value
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index where value is first located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search(array, 0, size - 1, value));
}
