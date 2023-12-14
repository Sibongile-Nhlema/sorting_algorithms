#include "sort.h"

void lomuto_sorting(int *array, size_t size, int left, int right);
int lomuto_partition(int *array, size_t size, int left, int right);

/**
 * quick_sort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm and lomuto partition scheme
 *
 * @array: the array of integers
 * @size: the size of the given array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sorting(array, size, 0, size - 1);
}

/**
 * lomuto_sorting - sorts the array using the lomuto partition
 *
 * @left_index: left most index of the array
 * @right_index: right most index of the array
 * @size: size of the array
 * @array: array of integers
 */
void lomuto_sorting(int *array, size_t size, int left_index, int right_index)
{
	int partition;

	/* If right index is greater than left index, split array */
	if (right_index - left_index > 0)
	{
		partition = lomuto_partition(array, size, left_index, right_index);
		lomuto_sorting(array, size, left_index, partition - 1);
		lomuto_sorting(array, size, partition + 1, right_index);
	}
}

/**
 * lomuto_partition - order a divsion of the array after split
 *
 * @array: array of integers
 * @size: size of the array
 * @left_index: left most index of the array
 * @right_index: right most index of the array
 */
int lomuto_partition(int *array, size_t size, int left_index, int right_index)
{
	int *pivot, above, below;

	pivot = array + right_index;
	below = left_index;
	above = left_index;

	while (below < right_index)
	{
		/* check If the current element is less than the pivot*/
		if (array[below] < *pivot)
		{
			/*Swap current element with element at above pointer*/
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			/*Move the above pointer one step forward*/
			above++;
		}
		/*Move the below pointer one step forward*/
		below++;
	}

	/*Swap pivot element with element at above pointer*/
	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}
/**
 * swap_int -  swaps the value of the integers
 *
 * @x: first integer
 * @y: second integer
 */
void swap_int(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
