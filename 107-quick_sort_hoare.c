#include "sort.h"

void swap_ints(int *x, int *y);
void hoare_sorting(int *array, size_t size, int left_index, int right_index);
int hoare_partition(int *array, size_t size, int left_index, int right_index);

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: pointer to the array of integers
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sorting(array, size, 0, size - 1);
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

/**
 * hoare_sorting - sorts the array using the hoare partition approach
 *
 * @left_index: left most index of the array
 * @right_index: right most index of the array
 * @size: size of the array
 * @array: pointer to the array of integers
 */
void hoare_sorting(int *array, size_t size, int left_index, int right_index)
{
	int partition;

	/* If right index is greater than left index, split array */
	if (right_index - left_index > 0)
	{
		partition = hoare_partition(array, size, left_index, right_index);
		hoare_sorting(array, size, left_index, partition - 1);
		hoare_sorting(array, size, partition, right_index);
	}
}

/**
 * hoare_partition - Perform Hoare partition scheme on an array of integers
 * based on a pivot element.
 *
 * (It looks for an element starting from left of that is >= pivot.
 * Similarly, it looks for an element starting from right that is <= pivot)
 *
 * @array: pointer to the array of integers
 * @size: size of the array
 * @left_index: left most index of the array
 * @right_index: right most index of the array
 *
 * Return: partition index at final index
 */
int hoare_partition(int *array, size_t size, int left_index, int right_index)
{
	int pivot, above, below;

	pivot = array[right_index];
	above = left_index - 1;
	below = right_index + 1;

	while (above < below)
	{
		/* Find first element from the left that is greater than pivot*/
		while (array[++above] < pivot)
			;
		/* Find first element from the right that is smaller than pivot*/
		while (array[--below] > pivot)
			;
		/*If indices have not crossed each other, swap elements */
		if (above < below)
		{
			swap_int(array + above, array + below);
			print_array(array, size);
		}
	}
	/* Return the index of pivot*/
	return (above);
}
