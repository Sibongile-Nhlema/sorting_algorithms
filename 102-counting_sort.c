#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order,
 * using the counting sort algorithm.
 *
 * @array: An array of integers
 * @size: The size of the array
*/
void counting_sort(int *array, size_t size)
{
	int *count_array, *array_copy, count = 0;
	size_t i, j;
	int k, largest_number = 0;

	array_copy = malloc(size * sizeof(int));
	if (array_copy == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		/*Find largest number in array*/
		if (array[i] > largest_number)
			largest_number = array[i];
		/*Copy array*/
		array_copy[i] = array[i];
	}

	count_array = malloc((largest_number + 1) * sizeof(int));
	if (count_array == NULL)
	{
		free(array_copy);
		return;
	}
	for (k = 0; k < largest_number + 1; k++)
	{
		/*Insert each number's occurence count in count_array,*/
		/*where the index represents the number*/
		for (j = 0; j < size; j++)
			if (array[j] == k)
				count++;
		count_array[k] = count;
		count = 0;
		/*Starting from the second index, add previous number to current one*/
		if (k != 0)
			count_array[k] += count_array[k - 1];
	}
	print_array(count_array, largest_number + 1);
	shift_elements_to_right(count_array, largest_number + 1);
	sort_array(array, array_copy, size, count_array);
	free(count_array), free(array_copy);
}

/**
 * shift_elements_to_right - Shifts the elements of an array
 * of integers to the right by 1.
 *
 * @array: An array of integers
 * @size: The size of the array
*/
void shift_elements_to_right(int *array, int size)
{
	int i;

	for (i = size - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			array[i] = 0;
		}
		else
		{
			array[i] = array[i - 1];
		}
	}
}

/**
 * sort_array - A helper function for counting_sort()
 * that places each element of an array of integers
 * in the right order based on it's corresponding index
 * in count_array.
 *
 * @array: An array of integers
 * @array_copy: A copy of array
 * @array_size: The size of array
 * @count_array: An array whose indices represent array's elements,
 * and whose elements represent array's element indices,
 * where they are to be placed to result in them being
 * in ascending order.
*/
void sort_array(int *array, int *array_copy, int array_size,
int *count_array)
{
	int i;
	int index, number;

	for (i = 0; i < array_size; i++)
	{
		number = array_copy[i];
		index = count_array[number];
		array[index] = number;
		index++;
	}
}
