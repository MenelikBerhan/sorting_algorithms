#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm. Prints the list after each swap.
 * @array: array of integers to be sorted
 * @size: size of array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest_index;
	int temp;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[smallest_index] > array[j])
				smallest_index = j;
		}
		if (smallest_index != i)
		{
			temp = array[i];
			array[i] = array[smallest_index];
			array[smallest_index] = temp;
			print_array(array, size);
		}
	}
}
