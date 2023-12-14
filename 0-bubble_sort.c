#include "sort.h"

/**
 * bubble_sort - sorts the set by swapping two adjacent values of one is bigger
 * than the other
 *
 * @array: pointer to the random array of integers
 * @size: number of elements in the array that needs to be sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (size == 0)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped++;
			}
		}
		if (swapped == 0)
			break;
	}
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
