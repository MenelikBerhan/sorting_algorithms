#include "sort.h"

/**
 * partition - partitions the array with the last element as a pivot
 * using the Hoare partition scheme.
 * @array: array of integers to be sorted
 * @low: index of range start
 * @high: index of range end
 * @size: size of array
 *
 * Return: the index where the array is partitioned at
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1, temp;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i > j)
			return (j);
		if (i == j)
			return (j - 1);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * q_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm. Prints the list after each swap.
 * @array: array of integers to be sorted
 * @low: index of range start
 * @high: index of range end
 * @size: size of array
 *
*/
void q_sort(int *array, int low, int high, size_t size)
{
	int p;

	if (high - low <= 0)
		return;

	p = partition(array, low, high, size);

	q_sort(array, low, p, size);
	q_sort(array, p + 1, high, size);
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * Quick sort algorithm with Hoare partition scheme. Prints the list after
 * each swap.
 * @array: array of integers to be sorted
 * @size: size of array
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
