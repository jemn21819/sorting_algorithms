#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	int min, max;

	if (!array || size < 2)
		return;
	min = 0;
	max = size - 1;
	_recursion(array, min, max, size);
}

/**
 * lomu_part - Lomuto partition scheme
 * @array: array to be sorted
 * @min: fist position array
 * @max: last position array
 * @size: size of the array
 * Return: index
 */

int lomu_part(int *array, int min, int max, size_t size)
{
	int pivot, i, j;

	pivot = array[max];
	i = min - 1;
	for (j = min; j <= max; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * swap - swap positions in array
 * @array: array to be sorted
 * @i: array position
 * @j: array position
 * Return: void
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * _recursion - recursion to call
 * @array: array to be sorted
 * @min: fist position in list
 * @max: las position
 * @size: size of teh array
 * Return: void
 */

void _recursion(int *array, size_t min, size_t max, size_t size)
{
	size_t i;

	if (min < max)
	{
		i = lomu_part(array, min, max, size);
		if (i > min)
			_recursion(array, min, i - 1, size);
		if (i < max)
			_recursion(array, i + 1, max, size);
	}
}
