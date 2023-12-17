#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*Sorting Functions*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/*Helper Functions*/
void quick_sort_helper(int *array, int left_pointer, int right_pointer,
size_t size);
int partition_array(int *array, int left_pointer, int right_pointer,
size_t size);
void shift_elements_to_right(int *array, int size);
void sort_array(int *array, int *array_copy, int array_size,
int *count_array);
void heapify_tree(int *array, size_t size, int length, int i);
void make_bitonic_sequence(int *array, int low_index, size_t size,
int direction, size_t original_size);
void bitonic_merge(int *array, int low_index, size_t size, int direction,
size_t original_size);

#endif
