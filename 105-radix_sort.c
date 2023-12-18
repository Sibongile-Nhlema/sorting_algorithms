#include "sort.h"

void custom_counting_sort(int *arr, size_t size, int position, int *b);
int getMax(int *arr, int size);

/**
 * radix_sort -  sorts an array of integers in ascending order
 * using the LSD Radix sort algorithm
 *
 * @array: pointer to the array of integers
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, position, *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	max = getMax(array, size);
	position = 1;
	while (max / position > 0)
	{
		custom_counting_sort(array, size, position, b);
		print_array(array, size);
		position *= 10;
	}
	free(b);
}

/**
 * getMax - find the maximum integer in the array
 * this is used as the key value
 *
 * @arr: pointer to the array of integers
 * @size: the size of the array
 *
 * Return: the maximun value in the array
 */
int getMax(int *arr, int size)
{
	int max = arr[0];
	int i = 1;

	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

/**
 * custom_counting_sort - sorts an array of integers in ascending order
 * using a custom plementation of the Counting sort algorithm
 *
 * @arr: pointer to the array of integers
 * @size: the size of the array
 * @position: the position of the digit(units, ten, hundreds etc)
 * @b: pointer to the buffer where the array is stored
 */
void custom_counting_sort(int *arr, size_t size, int position, int *b)
{
	int count_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count_array[(arr[i] / position) % 10] += 1;

	for (i = 0; i < 10; i++)
		count_array[i] += count_array[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		b[count_array[(arr[i] / position) % 10] - 1] = arr[i];
		count_array[(arr[i] / position) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		arr[i] = b[i];
}
