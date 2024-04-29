#include "sort.h"

/**
 * selection_sort - An implementation of the selection sorting algorithm
 *
 * @array: An array of integers to sort
 * @size: The length  of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t min;
	size_t i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
