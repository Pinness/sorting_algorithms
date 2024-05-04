#include <stdlib.h>
#include "sort.h"

/**
 * merge_array - A function to merge two arrays while sorting them instantly
 *
 * @array1: The first array we want to sort
 * @array2: The destination we want to sort into
 * @start: The beginning of the section we want to sort
 * @middle: The middle of the section we want to sort
 * @end: The end of the section we want to sort
 */

void merge_array(int *array1, int *array2, size_t start,
		size_t middle, size_t end)
{
	size_t i, j, k;

	i = start;
	j = start;
	k = middle + 1;
	/* While there are still elements in both range */
	while (j <= middle && k <= end)
	{
		if (array1[j] <= array1[k])
		{
			array2[i++] = array1[j++];
		}
		else
			array2[i++] = array1[k++];
	}
	/* When one of the range has been used up */
	while (j <= middle)
		array2[i++] = array1[j++];

	while (k <= end)
		array2[i++] = array1[k++];

}

/**
 * merge_sort_recursive - A recursive function for the merge sort
 *
 * @array1: The firts array
 * @array2: The second array
 * @size: The size of the array
 * @start: The start index of the section we want to sort
 * @end: The last index of the section we want to sort
 */

void merge_sort_recursive(int *array1, int *array2, size_t size,
		size_t start, size_t end)
{
	size_t middle, i;

	if ((end - start) < 1)
		return;
	if ((end + start) % 2 == 0)
		middle = (end + start - 1) / 2;
	else
		middle = (end + start) / 2;

	merge_sort_recursive(array2, array1, size, start, middle);
	merge_sort_recursive(array2, array1, size, middle + 1, end);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = start; i <= middle; i++)
	{
		if (i != start)
			printf(", ");
		printf("%d", array1[i]);
	}
	putchar('\n');
	printf("[right]: ");
	for (i = middle + 1; i <= end; i++)
	{
		if (i != middle + 1)
			printf(", ");
		printf("%d", array1[i]);
	}
	putchar('\n');
	merge_array(array1, array2, start, middle, end);
	printf("[Done]: ");
	for (i = start; i <= end; i++)
	{
		if (i != start)
			printf(", ");
		printf("%d", array2[i]);
	}
	putchar('\n');
}

/**
 * merge_sort - A merge sort algorithm that uses the top-down mechanism
 *
 * @array: The array we need to sort
 * @size: The size of the array to sort
 */

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
	merge_sort_recursive(array, array_copy, size, 0, size - 1);
	for (i = 0; i < size; i++)
		array[i] = array_copy[i];
	free(array_copy);
}
