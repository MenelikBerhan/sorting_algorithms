#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm. Prints the counting array once it is set up.
 * @array: array of integers to be sorted
 * @size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *output, *count;
	size_t i, max;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
		if (max < (unsigned int) array[i])
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		exit(EXIT_FAILURE);
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= max; i++)
		count[i] = count[i - 1] + count[i];
	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
		exit(EXIT_FAILURE);
	for (i = 0; i < size; i++)
		output[i] = -1;
	for (i = 0; i <= max; i++)
	{
		while (count[i])
		{
			if (output[count[i] - 1] == -1)
				output[count[i] - 1] = i;
			count[i] -= 1;
		}
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
