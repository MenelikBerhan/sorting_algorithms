#include "sort.h"

/**
 * bubble_sort - Sorts array of integers in ascending order using the
 * Bubble sort algorithm. Prints the array each time two elements are swapped.
 * @array: array of integers to be sorted
 * @size: size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, swapped;
	int temp;

	if (!array || size == 0)
		return;

	do {
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	} while (swapped);
}
