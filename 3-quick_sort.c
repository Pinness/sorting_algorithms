#include "sort.h"

void swap_items(int *array, size_t pos1, size_t pos2, size_t size)
{
	int temp;

	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
	print_array(array, size);
}

void qsort_recurse(int *array, size_t start, size_t pivot, size_t size)
{
	size_t i, switch_point;

	if (start == pivot)
		return;
	for (i = start; i <= pivot; i++)
	{
		if (array[i] > array[pivot])
		{
			if (switch_point && array[i] < array[switch_point])
				swap_items(array, i, switch_point, size);
			switch_point = i;
		}
	}
	if (switch_point)
		swap_items(array, switch_point, pivot, size);
	qsort_recurse(array, start, switch_point - 1, size);
	if (pivot != switch_point + 1)
		qsort_recurse(array, switch_point + 1, pivot, size);

}
/**
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot;
	size_t start;

	if (!array || size < 2)
		return;
	pivot = size - 1;
	start = 0;
	qsort_recurse(array, start, pivot, size);
}
