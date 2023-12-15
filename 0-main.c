#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	/*int array[] = {46, 69, 59, 25, 53, 53, 80, 7, 5, 48, 26, 86, 79,
	23, 90, 95, 12, 52, 68, 30, 18, 66, 57, 88, 88, 88, 10, 94, 21, 96, 72,
	54, 61, 3, 22, 83, 85, 98, 20, 2, 2, 2, 2, 2, 9, 44, 36, 77, 32, 35, 67, 99,
	19, 19, 19, 19, 19, 19, 19, 58, 24, 15, 81};*/
	size_t n = sizeof(array) / sizeof(array[0]);

	/*Test array*/
	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);

	return (0);
}
