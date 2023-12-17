#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order,
 * using the Bitonic sort algorithm.
 *
 * @array: An array of integers
 * @size: The size of the array
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	make_bitonic_sequence(array, 0, size, 1, size);
}

/**
 * make_bitonic_sequence - Sorts an array
 * by recursively making it into increasing and decreasing
 * bitonic sequences that get recursively merged
 * into one increasing sequence.
 *
 * @array: An array of integers
 * @low_index: A sequence's starting index
 * @size: The number of elements
 * @direction: 1 if ascending, 0 if descending
 * @original_size: The size of the whole array
*/
void make_bitonic_sequence(int *array, int low_index, size_t size,
int direction, size_t original_size)
{
	int k;

	if (size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", size, original_size,
		(direction) ? "UP" : "DOWN");
		print_array(array + low_index, size);

		k = size / 2;

		make_bitonic_sequence(array, low_index, k, 1, original_size);
		make_bitonic_sequence(array, (low_index + k), k, 0, original_size);
		bitonic_merge(array, low_index, size, direction, original_size);

		printf("Result [%lu/%lu] (%s):\n", size, original_size,
		(direction) ? "UP" : "DOWN");
		print_array(array + low_index, size);
	}
}

/**
 * bitonic_merge - Recursively merges bitonic sequences into one
 * ordered sequence.
 *
 * @array: An array of integers
 * @low_index: A sequence's starting index
 * @size: The number of elements
 * @direction: 1 if ascending, 0 if descending
 * @original_size: The size of the whole array
*/
void bitonic_merge(int *array, int low_index, size_t size, int direction,
size_t original_size)
{
	int k, i;
	int temp;

	if (size > 1)
	{
		k = size / 2;

		for (i = low_index; i < low_index + k; i++)
		{
			if (direction == (array[i] > array[i + k]))
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

		bitonic_merge(array, low_index, k, direction, original_size);
		bitonic_merge(array, (low_index + k), k, direction, original_size);
	}
}
