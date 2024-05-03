#include <stdlib.h>
#include "sort.h"

void merge_array(int *array1, int *array2, size_t start, size_t middle, size_t end)
{
	size_t i, j, k;

	j = start;
	k = middle;
	for (i = start; i < end; i++)
	{
		if (j < middle && (k >= end || array1[j] <= array1[k]))
		{
			array2[i] = array1[j];
			j++;
		}
		else
		{
			array2[i] = array1[k];
			k++;
		}
	}
}

void merge_sort_recursive(int *array1, int *array2, size_t size, size_t start, size_t end)
{
	size_t middle;

	if ((start - end) <= 1)
		return;
	middle = (end + start) / 2;

	merge_sort_recursive(array2, array1, size, start, middle);
	merge_sort_recursive(array2, array1, size, middle, end);
	merge_array(array1, array2, start, middle, end);
}

void merge_sort(int *array, size_t size)
{
	int *array_copy;
	size_t i;

	if (!array || size < 2)
		return;
	array_copy = malloc(sizeof(int) * size);
	if (!array_copy)
		return;
	/* Copy input array into the malloced array */
	for (i = 0; i < size; i++)
		array_copy[i] = array[i];
	merge_sort_recursive(array, array_copy, size, 0, size);
	print_array(array_copy, size);
	free(array_copy);
}
