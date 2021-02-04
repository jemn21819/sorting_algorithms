#include "sort.h"

/**
 * TDMS - sort and merges
 * @left: starting index
 * @mid: mid of index
 * @right: end index
 * @out: resultant data
 * @array: array to be sorted
 * Return: void
 */

void TDMS(size_t left, size_t mid, size_t right, int *out, int *array)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);
	i = left;
	j = mid;
	for (k = left; k < right; k++)
	{
		if (i < mid && (j >= right || array[i] <= array[j]))
		{
			out[k] = array[i];
			i++;
		}
		else
		{
			out[k] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(out + left, right - left);
}

/**
 * TDSplitMerge - splite and merge the stored array
 * @left: start index
 * @right: end index
 * @array: array to be sorted
 * @copy: copy of the array
 * Return: void
 */

void TDSplitMerge(size_t left, size_t right, int *array, int *copy)
{
	size_t mid;

	if (right - left < 2)
		return;
	mid = (left + right) / 2;
	TDSplitMerge(left, mid, array, copy);
	TDSplitMerge(mid, right, array, copy);
	TDMS(left, mid, right, array, copy);
	for (mid = left; mid < right; mid++)
		copy[mid] = array[mid];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Marge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (!array || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
