# include "sort.h"

/**
 * shell_sort -  sorts an array of integers in ascending
 * order using the Shell sort
 * @array: array to be sorted
 * @size: size of the array
 * Retrun: Void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int put;

	if (!array || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			put = array[i];
			for (j = i; j >= gap && array[j - gap] > put; j = j - gap)
				array[j] = array[j - gap];
			array[j] = put;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
