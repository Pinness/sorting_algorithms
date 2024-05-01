#include "sort.h"

/**
 * insert_shell - A function to perform insertions on
 * stepped intervals of the array
 *
 * @array: The array we are sorting
 * @size: The length of the array
 * @tail: The index of the first element of the step
 * interval
 * @step: The current step we are working with
 */

void insert_shell(int *array, size_t size, size_t tail, size_t step)
{
	size_t moving;
	int temp;

	while (tail < size)
	{
		moving = tail + step;
		if (moving >= size)
			break;
		if (array[moving] < array[tail])
		{
			temp = array[moving];
			array[moving] = array[tail];
			array[tail] = temp;
			if (tail >= step)
				tail = tail - step;
			else
				tail = tail + step;
		}
		else
			tail = tail + step;
	}
}

/**
 * shell_sort - An implementation of the shell sort
 * algorithm using the Knuth sequence
 *
 * @array: The array to sort
 * @size: The number of elements in the array
*/

void shell_sort(int *array, size_t size)
{
	size_t step;
	size_t i;

	if (!array || size < 2)
		return;

	step = 1;
	while (step < size)
		step = (step * 3) + 1;
	step = (step - 1) / 3;

	while (step > 0)
	{
		i = 0;
		while (i < step)
		{
			insert_shell(array, size, i, step);
			i++;
		}
		step = (step - 1) / 3;
		print_array(array, size);
	}
}
