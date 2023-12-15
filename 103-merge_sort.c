#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, int *buffer, size_t front, size_t back);
void merge_arrays(int *array, int *buffer,
		size_t front, size_t mid, size_t back);

/**
 * merge_sort - Sort an array of integers in ascending order
 * using merge sort algorithm
 * Implements the top-down merge sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size <= 1)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);
	free(buffer);
}

/**
 * merge_sort_recursive - merge sort using recursion
 *
 * @array: array to sort
 * @buffer: buffer to store results
 * @front: front index of the subarray to sort
 * @back: back index of the subarray to sort
 */
void merge_sort_recursive(int *array, int *buffer, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;

		/* Sort first half of the array */
		merge_sort_recursive(array, buffer, front, mid);
		/* Sort second half of the array */
		merge_sort_recursive(array, buffer, mid, back);
		/* Merge the sorted subarrays*/
		merge_arrays(array, buffer, front, mid, back);
	}
}

/**
 * merge_arrays - Merge two sorted subarrays into one sorted array
 *
 * @array: array containing subarrays to merge
 * @buffer: buffer to store merged subarrays
 * @front: front index of first subarray
 * @mid: middle index separating the two subarrays
 * @back: back index of second subarray
 */
void merge_arrays(int *array, int *buffer,
		size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + front, mid - front);
	printf("[right]: ");
	print_array(array + mid, back - mid);

	i = front;
	j = mid;
	k = 0;
	/* Merge the two subarrays into the buffer */
	while (i < mid && j < back)
	{
		if (array[i] < array[j])
		{
			buffer[k] = array[i];
			i++;
		}
		else
		{
			buffer[k] = array[j];
			j++;
		}
		k++;
	}
	/* Copy remaining elements from left subarray to buffer */
	while (i < mid)
		buffer[k++] = array[i++];
	/* Copy remaining elements from right subarray to buffer */
	while (j < back)
		buffer[k++] = array[j++];

	i = front;
	k = 0;
	/* Copy merged elements from the buffer back to original array */
	while (i < back)
		array[i++] = buffer[k++];

	printf("[Done]: ");
	print_array(array + front, back - front);
}
