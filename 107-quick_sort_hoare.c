#include "sort.h"

/**
 * _partition - look for a partition to sort
 * @array: array to be sorted
 * @min: lowest index
 * @max: highest index
 * @size: size of the array
 * Return: index
 */

size_t _partition(int *array, ssize_t min, ssize_t max, size_t size)
{
	int temp, pivot;

	pivot = array[max];
	while (min <= max)
	{
		while (array[min] < pivot)
			min++;
		while (array[max] > pivot)
			max--;
		if (min <= max)
		{
			if (min != max)
			{
				temp = array[min];
				array[min] = array[max];
				array[max] = temp;
				print_array(array, size);
			}
			min++;
			max--;
		}
	}
	return (max);
}

/**
 * _sorting - sort partition
 * @array: array to be sorted
 * @min: lowest index
 * @max:highest index
 * @size: size array
 * Return: void
 */

void _sorting(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = _partition(array, min, max, size);
		_sorting(array, min, pivot, size);
		_sorting(array, pivot + 1, max, size);
	}
}

/**
 * quick_sort_hoare -  sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Void
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	_sorting(array, 0, size - 1, size);
}
