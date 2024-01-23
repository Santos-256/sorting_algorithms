#include "sort.h"

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
	int maximum, k;

	for (maximum = array[0], k = 1; k < size; k++)
	{
		if (array[k] > maximum)
			maximum = array[k];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 *
 * @array: An array of integers.
 *
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maximum, j;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = get_max(array, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (j = 0; j < (maximum + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] += 1;
	for (j = 0; j < (maximum + 1); j++)
		count[j] += count[j - 1];
	print_array(count, maximum + 1);

	for (j = 0; j < (int)size; j++)
	{
		sorted[count[array[j]] - 1] = array[j];
		count[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];

	free(sorted);
	free(count);
}
