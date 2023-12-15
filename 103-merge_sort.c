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

	merge_sort_recursive(array, buffer, 0, size - 1);
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
	size_t mid, i;

	if (front < back)
	{
		mid = front + (back - front) / 2;

		/* Sort first half of the array */
		merge_sort_recursive(array, buffer, front, mid);
		/* Sort second half of the array */
		merge_sort_recursive(array, buffer, mid + 1, back);
		/* Merge the sorted subarrays*/
		printf("Merging... \n");
		printf("[left]: ");
		for (i = front; i <= mid; i++)
		{
			printf("%d", array[i]);
			if (i != mid)
				printf(", ");
		}
		printf("\n");
		printf("[right]: ");
		for (i = mid + 1; i <= back; i++)
		{
			printf("%d", array[i]);
			if (i != back)
				printf(", ");
		}
		printf("\n");
		merge_arrays(array, buffer, front, mid, back);
		printf("[Done]: ");
		for (i = front; i <= back; i++)
		{
			printf("%d", array[i]);
			if (i != back)
				printf(", ");
		}
		printf("\n");
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
	size_t i, j, k;

	/* Copy subarrays into buffer */
	for (i = front; i <= back; i++)
		buffer[i] = array[i];
	i = front;
	j = mid + 1;
	k = front;
	/* Merge subarrays in sorted order */
	while (i <= mid && j <= back)
	{
		if (buffer[i] <= buffer[j])
		{
			array[k] = buffer[i];
			i++;
		}
		else
		{
			array[k] = buffer[j];
			j++;
		}
		k++;
	}
	/* Copy remaining elements from first subarray */
	while (i <= mid)
	{
		array[k] = buffer[i];
		i++;
		k++;
	}
	/* Copy remaining elements from second subarray */
	while (j <= back)
	{
		array[k] = buffer[j];
		j++;
		k++;
	}
}
