#include "sort.h"

/**
 * insertion_sort_list - sorts the list by finding the smallest value
 * and moving it to the beginning of the list.
 *
 * @list: double pointer to the linked list
 */
void insertion_sort_list(listint_t **list)
{
	int current_value;
	listint_t  *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = next_node)
	{
		next_node = current->next;
		prev_node = current->prev;
		current_value = current->n;

		while (prev_node != NULL && current_value < prev_node->n)
		{
			swap_nodes(list, &prev_node, current);
			print_list((const listint_t *)*list);
		}
	}
}


/**
 * swap_nodes - swaps the address of the nodes
 *
 * @h: double pointer to the linked list
 * @node1: pointer to first node
 * @node2: pointer to second node
 */
void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
