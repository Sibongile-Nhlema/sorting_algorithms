#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);
	clock_t start_time, end_time;
	double time_taken;

	print_array(array, n);
	printf("\n");

	start_time = clock();
	bubble_sort(array, n);
	end_time = clock();

	printf("\n");
	print_array(array, n);

	time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Time taken to completed the sort fo array: %f seconds\n", time_taken);
	return (0);
}
