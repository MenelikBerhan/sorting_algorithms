#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bitonicMerge - merges two subarrays in a specified order
 * @arr: array to be sorted
 * @low: starting index
 * @size: number of elements to be sorted
 * @direction: 1 for ascending order, 0 for descending order
 */
void bitonicMerge(int *arr, int low, int size, int direction)
{
	int k = size / 2, i;

	if (size < 2)
		return;
	for (i = low; i < low + k; i++)
		if (direction == (arr[i] > arr[i + k]))
			swap(&arr[i], &arr[i + k]);
	bitonicMerge(arr, low, k, direction);
	bitonicMerge(arr, low + k, k, direction);
}

/**
 * bitonicSort - sorts an array in a specified order
 * @arr: array to be sorted
 * @low: starting index
 * @size: number of elements to be sorted
 * @full_size: size of the full array
 * @direction: 1 for ascending order, 0 for descending order
 */
void bitonicSort(int *arr, int low, int size, int full_size, int direction)
{
	int k = size / 2;

	if (size < 2)
		return;
	printf("Merging [%d/%d] (%s):\n", size, full_size, direction ? "UP" : "DOWN");
	print_array(arr + low, size);
	bitonicSort(arr, low, k, full_size, 1);
	bitonicSort(arr, low + k, k, full_size, 0);
	bitonicMerge(arr, low, size, direction);
	printf("Result [%d/%d] (%s):\n", size, full_size, direction ? "UP" : "DOWN");
	print_array(arr + low, size);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	bitonicSort(array, 0, size, size, 1);
}
