#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @int_1: The first integer to swap.
 * @int_2: The second integer to swap.
 */
void swap_ints(int *int_1, int *int_2)
{
	int tmp;

	tmp = *int_1;
	*int_1 = *int_2;
	*int_2 = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t j;
	size_t k;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			k = j;
			while (k >= gap && array[k - gap] > array[k])
			{
				swap_ints(array + k, array + (k - gap));
				k -= gap;
			}
		}
		print_array(array, size);
	}
}
