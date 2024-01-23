#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maximum, index;

	for (maximum = array[0], index = 1; index < size; index++)
	{
		if (array[index] > maximum)
			maximum = array[index];
	}

	return (maximum);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * @sig: The significant digit to sort on.
 *
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t index;

	for (index = 0; index < size; index++)
		count[(array[index] / sig) % 10] += 1;

	for (index = 0; index < 10; index++)
		count[index] += count[index - 1];

	for (index = size - 1; (int)index >= 0; index--)
	{
		buff[count[(array[index] / sig) % 10] - 1] = array[index];
		count[(array[index] / sig) % 10] -= 1;
	}

	for (index = 0; index < size; index++)
		array[index] = buff[index];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, siginificant_digit, *temp_buffer;

	if (array == NULL || size < 2)
		return;

	temp_buffer = malloc(sizeof(int) * size);
	if (temp_buffer == NULL)
		return;

	maximum = get_max(array, size);
	for (siginificant_digit = 1; maximum / siginificant_digit > 0;
			siginificant_digit *= 10)
	{
		radix_counting_sort(array, size, siginificant_digit, temp_buffer);
		print_array(array, size);
	}

	free(temp_buffer);
}
