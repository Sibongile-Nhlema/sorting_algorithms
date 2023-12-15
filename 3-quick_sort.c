#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm, utilizing the Lomuto
 * partition scheme.
 *
 * @array: A pointer to an array of integers.
 * @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - Sorts an array of integers in ascending order
 * using the Quick sort algorithm, utilizing the Lomuto
 * partition scheme.
 *
 * @array: A pointer to an array of integers.
 * @left_pointer: The index of an element in the array which marks
 * the beginning of a partition to sort.
 * @right_pointer: The index of an element in the array which marks
 * the end of a partition to sort.
 * @size: The size of the array.
*/
void quick_sort_helper(int *array, int left_pointer, int right_pointer,
size_t size)
{
	int pivot_index;

	if (left_pointer >= right_pointer)
	{
		return;
	}

	pivot_index = partition_array(array, left_pointer, right_pointer, size);

	quick_sort_helper(array, left_pointer, pivot_index - 1, size);
	quick_sort_helper(array, pivot_index + 1, right_pointer, size);
}

/**
 * partition_array - Places the pivot in a partition
 * marked by two pointers (left_pointer and right_ pointer)
 * so that the elements preceding the pivot are smaller
 * than the pivot and the ones following the pivot are
 * larger than it.
 *
 * @array: A pointer to an array of integers.
 * @left_pointer: The index of an element in the array which marks
 * the beginning of a partition to sort.
 * @right_pointer: The index of an element in the array which marks
 * the end of a partition to sort.
 * @size: The size of the array.
 *
 * Return: Returns the index of the new pivot.
*/
int partition_array(int *array, int left_pointer, int right_pointer,
size_t size)
{
	int pivot, temp;
	int i, j;

	pivot = array[right_pointer];
	i = left_pointer - 1;

	for (j = left_pointer; j < right_pointer; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
			{
				print_array(array, size);
			}
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[right_pointer];
	array[right_pointer] = temp;
	if ((i + 1) != right_pointer)
	{
		print_array(array, size);
	}

	return (i + 1);
}
