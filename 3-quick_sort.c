#include "sort.h"

/**
 * swap_items - A function to swap two entries in the array
 *
 * @array: The array containing the values we want to swap
 * @pos1: The index of the first item
 * @pos2: The index of the second item
 * @size: The size of the array
 */

void swap_items(int *array, size_t pos1, size_t pos2, size_t size)
{
	int temp;

	if (pos1 == pos2)
		return;
	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
	print_array(array, size);
}

/**
 * qsort_recurse - A recursive curl of the qsort algorithm
 * using Lomuto's scheme
 *
 * @array: The array we want to sort
 * @start: The starting index of the partition
 * @pivot: The pivot of choice which is the last index of the partition
 * @size: The lenght of the array
 */

void qsort_recurse(int *array, size_t start, size_t pivot, size_t size)
{
	size_t i, switch_point;

	if (start >= pivot)
		return;
	switch_point = start;
	for (i = start; i < pivot; i++)
	{
		if (array[i] <= array[pivot])
		{
			swap_items(array, i, switch_point, size);
			switch_point++;
		}
	}
	swap_items(array, switch_point, pivot, size);
	if (switch_point > start)
		qsort_recurse(array, start, switch_point - 1, size);
	qsort_recurse(array, switch_point + 1, pivot, size);

}

/**
 * quick_sort - An implementation of the quick sort algorithm
 *
 * @array: The array we want to sort
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qsort_recurse(array, 0, size - 1, size);
}
