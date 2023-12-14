#include "sort.h"

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
