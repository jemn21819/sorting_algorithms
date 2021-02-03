#include "sort.h"

/**
 * couting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	size_t i, temp, total = 0;
	int j, max;
	int *count = NULL, *copy = NULL;

	if (!array || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (i = 0, max = 0; i < size; i++)
	{
		copy[i] = array[i];
		if (array[i] > max)
			max = array[i];
	}
	count =malloc(sizeof(int) * (max+ 1));
	if (!count)
	{
		free(copy);
		return;
	}
	for (j = 0; j <= max; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (j = 0; j <= max; j++)
	{
		temp = count[j];
		count[j] = total;
		total += temp;
	}
	for (i = 0; i < size; i++)
	{
		array[count[copy[i]]] = copy[i];
		count[copy[i]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(copy);
}
