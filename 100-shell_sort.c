#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence. Prints the list everytime
 * the interval is decreased.
 * @array: array of integers to be sorted
 * @size: size of array
 *
 */
void shell_sort(int *array, size_t size)
{
	int interval = 0, current, prev, len = size;
	int temp, start_index;

	if (!array || size == 0)
		return;

	while (interval <= len - 1)
		interval = interval * 3 + 1;
	interval = (interval - 1) / 3;
	while (interval > 0)
	{
		for (start_index = 0; start_index < interval; start_index++)
		{
			current = start_index;
			while (current + interval < len)
			{
				if (array[current] > array[current + interval])
				{
					temp = array[current];
					array[current] = array[current + interval];
					array[current + interval] = temp;

					prev = current;
					while (prev - interval >= 0 && array[prev] < array[prev - interval])
					{
						temp = array[prev];
						array[prev] = array[prev - interval];
						array[prev - interval] = temp;
						prev -= interval;
					}
				}
				current += interval;
			}
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
