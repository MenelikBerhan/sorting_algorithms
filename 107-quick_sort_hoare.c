#include "sort.h"

/**
 * partition - partitions the array with the last element as a pivot
 * using the Hoare partition scheme.
 * @array: array of integers to be sorted
 * @low: index of range start
 * @high: index of range end
 * @size: size of array
 *
 * Return: the index where the pivot is at
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = high;
	i = low;
	j = high;
	while (j >= i)
	{
		while (array[i] <= array[pivot] && i < high)
			i++;
		while (array[j] > array[pivot] && j >= low)
			j--;
		if (i == pivot || (j == pivot && j != high))
			return (pivot);

		if (j > i && array[i] > array[j])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (j == pivot)
				pivot = i;
			i++;
			j--;
			print_array(array, size);
		}
	}
	if (array[pivot] > array[j])
		pivot = -j;

	return (pivot);
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

	if (low >= high || low < 0)
		return;

	p = partition(array, low, high, size);

	q_sort(array, low, (p < 0 ? -p : p - 1), size);
	q_sort(array, (p < 0 ? (-p + 1) : p + 1), high, size);
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
