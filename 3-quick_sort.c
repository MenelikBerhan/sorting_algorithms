#include "sort.h"

/**
 * partition - partitions the array with the last element as a pivot
 * using Lomuto's partitoning scheme.
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

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i += 1;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i += 1;
	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
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
	q_sort(array, low, p - 1, size);
	q_sort(array, p + 1, high, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm. Prints the list after each swap.
 * @array: array of integers to be sorted
 * @size: size of array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
