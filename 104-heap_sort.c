#include "sort.h"

void heapify(int *arr, size_t size, size_t i){};

/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);
}