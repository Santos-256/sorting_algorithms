#include "sort.h"

/**
 * swap_ints - Swap two integers in an array in the program
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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t j, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
