#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order,
 * using the Shell sort algorithm, utilizing the Knuth sequence.
 *
 * @array: A pointer to an array of integers.
 * @size: The size of the array.
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j, increment;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	/*Determine initial increment based on Knuth sequence*/
	for (increment = 1; increment < size / 3; increment = increment * 3 + 1)
		;
	for (; increment > 0; increment /= 3)
	{
		/*Perform insertion sort within each interval*/
		for (i = increment; i < size; i++)
		{
			temp = array[i];

			/*Compare elements within the interval and swap if necessary*/
			for (j = i; j >= increment && temp < array[j - increment]; j -= increment)
			{
				array[j] = array[j - increment];
			}

			/*Place the current element in its correct position within the interval*/
			array[j] = temp;
		}
		print_array(array, size);
	}
}
