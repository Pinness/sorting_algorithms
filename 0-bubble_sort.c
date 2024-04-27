#include "sort.h"

/**
 * bubble_sort - An implementation of the bubble
 * sort algorithm
 *
 * @array: The array to sort
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t ind;
	int swapped;

	if (size < 2)
		return;
	swapped = 0;
	do {
		swapped = 0;
		for (ind = 0; ind < size - 1; ind++)
		{
			if (array[ind] > array[ind + 1])
			{
				temp = array[ind];
				array[ind] = array[ind + 1];
				array[ind + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	} while (swapped);
}
