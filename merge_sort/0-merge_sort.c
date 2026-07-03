#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - merges two sorted subarrays
 * @array: array to sort
 * @buffer: temporary buffer
 * @left: start index of the left subarray
 * @mid: start index of the right subarray
 * @right: end index of the right subarray
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = left;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}

	while (i < mid)
		buffer[k++] = array[i++];

	while (j < right)
		buffer[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_recursive - recursively sorts an array using merge sort
 * @array: array to sort
 * @buffer: temporary buffer
 * @left: start index of the current subarray
 * @right: end index of the current subarray
 */
void merge_recursive(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	merge_recursive(array, buffer, left, mid);
	merge_recursive(array, buffer, mid, right);
	merge(array, buffer, left, mid, right);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_recursive(array, buffer, 0, size);

	free(buffer);
}
