#include "sort.h"

void swap_ints(int *int_1, int *int_2);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme (last element as pivot).
 *
 * @array: The array of integers.
 *
 * @size: The size of an array.
 *
 * @left: The starting index of the subset to order.
 *
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *center, upper, lower;

	center = array + right;
	for (upper = lower = left; lower < right; lower++)
	{
		if (array[lower] < *center)
		{
			if (upper < lower)
			{
				swap_ints(array + lower, array + upper);
				print_array(array, size);
			}
			upper++;
		}
	}

	if (array[upper] > *center)
	{
		swap_ints(array + upper, center);
		print_array(array, size);
	}

	return (upper);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 *
 * @size: The size of the array.
 *
 * @left: The starting index of the array partition to order.
 *
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int section;

	if (right - left > 0)
	{
		section = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, section - 1);
		lomuto_sort(array, size, section + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 * the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
