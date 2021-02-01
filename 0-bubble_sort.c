#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: array to be sorted by fucntion
 * @size: Size of  the array to be sorted
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t tmp;

	for (i = 0; i < size; i++)
	{
		/*first loop of fisrt position*/
		for (j = 0; j < size - 1; j++)
		{
			/*another loop for the last sorted*/
			if (array[j] > array[j + 1])
			{
				/*swap elements*/
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
