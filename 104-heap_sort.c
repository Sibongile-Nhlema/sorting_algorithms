#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order,
 * using the sift-down Heap sort algorithm.
 *
 * @array: An array of integers
 * @size: The length of the array
*/
void heap_sort(int *array, size_t size)
{
	int temp;
	int i;
	int length = size;

	if (array == NULL || length < 2)
	{
		return;
	}

	/* Build the max heap */
	for (i = (length / 2) - 1; i >= 0; i--)
	{
		heapify_tree(array, size, length, i);
	}

	/* Extract elements from the heap, one by one */
	for (i = length - 1; i > 0; i--)
	{
		/* Swap the root (maximum element) with the last element */
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		/**
		 * Recreate the max heap with the reduced array
		 * (ignoring the already-sorted elements at the end of the array)
		 */
		heapify_tree(array, size, i, 0);
	}
}

/**
 * heapify_tree - Heapifies a tree within an array.
 *
 * @array: An array of integers
 * @size: The size of the whole array
 * @length: The length of the array minus the sorted elements
 * @i: An index at which to sift-down
*/
void heapify_tree(int *array, size_t size, int length, int i)
{
	int temp;
	int largest_i, left_i, right_i;

	largest_i = i;
	/* Left child index */
	left_i = 2 * i + 1;
	/* Right child index */
	right_i = left_i + 1;

	/* Check if left child is larger than the current largest */
	if (left_i < length && array[left_i] > array[i])
	{
		largest_i = left_i;
	}
	/* Check if right child is larger than the current largest */
	if (right_i < length && array[right_i] > array[largest_i])
	{
		largest_i = right_i;
	}

	/* If the largest element is not the current root */
	if (largest_i != i)
	{
		/* Swap the elements and print the array */
		temp = array[i];
		array[i] = array[largest_i];
		array[largest_i] = temp;
		print_array(array, size);

		/* Recursively heapify the affected subtree */
		heapify_tree(array, size, length, largest_i);
	}
}
