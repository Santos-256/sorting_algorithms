#include "sort.h"

void swap_ints(int *int_1, int *int_2);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 *
 * @array: An array of integers representing a binary tree.
 *
 * @size: The size of the array/tree.
 *
 * @base: The index of the base row of the tree.
 *
 * @root: The root node of the binary tree.
 *
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, center;

	left = 2 * root + 1;
	right = 2 * root + 2;
	center = root;

	if (left < base && array[left] > array[center])
		center = left;
	if (right < base && array[right] > array[center])
		center = right;

	if (center != root)
	{
		swap_ints(array + root, array + center);
		print_array(array, size);
		max_heapify(array, size, base, center);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int index;

	if (array == NULL || size < 2)
		return;

	for (index = (size / 2) - 1; index >= 0; index--)
		max_heapify(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		swap_ints(array, array + index);
		print_array(array, size);
		max_heapify(array, size, index, 0);
	}
}
