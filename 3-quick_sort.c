#include "sort.h"

void swap_int(int *x, int *y);
/**
 * quick_sort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm and lomuto partition scheme
 *
 * @array: the array of integers
 * @size: the size of the given array
 */
void quick_sort(int *array, size_t size)
{
	size_t i;
	int pivot, partition_boundary;

	if (array == NULL || size < 2)
		return;

	partition_boundary = 0;
	pivot = array[size -1];
	for (i = 0; i < size; i++)
	{
		if (array[i] <= pivot)
		{
			swap_int(&array[i], &array[partition_boundary]);
			partition_boundary++;	
		}
	}
	swap_int(&array[size - 1], &array[partition_boundary]);

	if (partition_boundary > 1)
		quick_sort(array, partition_boundary);/*left array*/
	if (size - partition_boundary - 1 > 1)
		quick_sort(array + partition_boundary + 1, size - partition_boundary - 1);
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
