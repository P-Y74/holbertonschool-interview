#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - restores the max-heap property
 * @array: array to sort
 * @size: total size of the array
 * @heap_size: current heap size
 * @root: root index to sift down
 */
void sift_down(int *array, size_t size,
			   size_t heap_size, size_t root)
{
	size_t largest;
	size_t left;
	size_t right;

	while (1)
	{
		largest = root;
		left = 2 * root + 1;
		right = 2 * root + 2;

		if (left < heap_size && array[left] > array[largest])
			largest = left;

		if (right < heap_size && array[right] > array[largest])
			largest = right;

		if (largest == root)
			break;

		swap(&array[root], &array[largest]);
		print_array(array, size);

		root = largest;
	}
}

/**
 * heap_sort - sorts an array using Heap sort
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	size_t end;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, size, i - 1);

	for (end = size - 1; end > 0; end--)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		sift_down(array, size, end, 0);
	}
}
