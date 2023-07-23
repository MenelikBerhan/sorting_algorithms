#include "sort.h"

/**
 * merge - marges 2 subarrays of an array into sorted form
 * @arr: main array
 * @l: start point of the first sub array
 * @m: mid point
 * @r: end poing of the second sub array
 */
void merge(int *arr, size_t l, size_t m, size_t r)
{
	size_t i, j, k, n1 = m - l + 1, n2 = r - m;
	int L[1000], R[1000];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	printf("Merging...\n[left]: ");
	print_array(L, n1);
	printf("[right]: ");
	print_array(R, n2);
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
	printf("[Done]: ");
	print_array(&arr[l], k - l);
}

/**
 * merge_sort_helper - recursively calls itself to sort the array of integers
 * @arr: array to be sorted
 * @l: starting index of the sub array of arr under review
 * @r: end index of sub array of arr under review
 */
void merge_sort_helper(int *arr, size_t l, size_t r)
{
	if (l < r)
	{
		size_t mid = (l + (r - 1)) / 2;

		merge_sort_helper(arr, l, mid);
		merge_sort_helper(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	merge_sort_helper(array, 0, size - 1);
}
