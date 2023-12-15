#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending
 * order using the selection sort algorithm.
 *
 * @array: A pointer to an array of integers.
 * @size: The size of the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest_index;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		smallest_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_index])
			{
				smallest_index = j;
			}
		}

		if (smallest_index != i)
		{
			temp = array[i];
			array[i] = array[smallest_index];
			array[smallest_index] = temp;
			print_array(array, size);
		}
	}
}
