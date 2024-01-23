#include "sort.h"

void swap_ints(int *int_1, int *int_2);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @int_1: The first integer to swap.
 * @int_2: The second integer to swap.
 */
void swap_ints(int *int_1, int *int_2)
{
	int temp;

	temp = *int_1;
	*int_1 = *int_2;
	*int_2 = temp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 * according to the hoare partition scheme
 * and takes function of an array.
 *
 * @array: The array of integers.
 *
 * @size: The size of the array.
 *
 * @left: The starting index of the subset to order.
 *
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int center;
	int upper;
	int lower;

	center = array[right];
	for (upper = left - 1, lower = right + 1; upper < lower;)
	{
		do {
			upper++;
		} while (array[upper] < center);
		do {
			lower--;
		} while (array[lower] > center);

		if (upper < lower)
		{
			swap_ints(array + upper, array + lower);
			print_array(array, size);
		}
	}

	return (upper);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 *
 * @array: An array of integers to sort.
 *
 * @size: The size of the array.
 *
 * @left: The starting index of the array partition to order.
 *
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm
 * and used in the partitioning scheme.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
