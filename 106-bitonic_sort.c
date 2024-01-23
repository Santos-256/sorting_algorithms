/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_ints(int *int_1, int *int_2);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * @start: The starting index of the sequence in array to sort.
 *
 * @seq: The size of the sequence to sort.
 *
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t index, jump = seq / 2;

	if (seq > 1)
	{
		for (index = start; index < start + jump; index++)
		{
			if ((flow == UP && array[index] > array[index + jump]) ||
			    (flow == DOWN && array[index] < array[index + jump]))
				swap_ints(array + index, array + index + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Converts an array of integers into a bitonic sequence.
 *
 * @array: An array of integers.
 *
 * @size: The size of an array.
 *
 * @start: The starting index of a block of the building bitonic sequence.
 *
 * @seq: The size of a block of the building bitonic sequence.
 *
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t ptr = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, ptr, UP);
		bitonic_seq(array, size, start + ptr, ptr, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap and Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
