#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - A funtion that implements the counting sorting algorithm
 *
 * @array: The array we want to sort
 * @size: The number of elements in the array
 */

void counting_sort(int *array, size_t size)
{
	int *count_array;
	int *output_array;
	size_t max_value, i;
	int key;

	if (!array || size < 2)
		return;
	max_value = 0;
	for (i = 0; i < size; i++)
		if (array[i] > (int)max_value)
			max_value = array[i];
	count_array = calloc(max_value + 1, sizeof(int));
	if (!count_array)
		return;
	output_array = malloc(sizeof(int) * size);
	if (!output_array)
	{
		free(count_array);
		return;
	}
	/* Collecting the frequency of the items in the input array */
	for (i = 0; i < size; i++)
	{
		key = array[i];
		count_array[key] = count_array[key] + 1;
	}
	/* Prefix accumulator */
	for (i = 1; i <= max_value; i++)
		count_array[i] = count_array[i] + count_array[i - 1];

	print_array(count_array, max_value + 1);
	for (i = size - 1; (int)i >= 0; i--)
	{
		count_array[array[i]] = count_array[array[i]] - 1;
		output_array[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(output_array);
	free(count_array);
}
