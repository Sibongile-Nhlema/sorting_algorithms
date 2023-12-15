#include "sort.h"

void swap_node_after(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_before(listint_t **list, listint_t **tail, listint_t **shaker);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: linked list with integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	int shook = 0;

	/* check if list is empty or has one element*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/*find last element*/
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shook == 0)
	{
		shook = 1;
		current = *list;

		/*Forward- Traverse the list from the beginning to end*/
		while (current != tail)
		{
			if (current->n > current->next->n)
			{
				swap_node_before(list, &tail, &current);
				print_list((const listint_t *)*list);
				shook = 0;
			}
			current = current->next;
		}
		/* if no swaps are made, break loop*/
		if (shook == 1)
			break;
		shook = 1;
		current = tail;

		/* Backwards- Traverse the list from end to the beginning*/
		while (current != *list)
		{
			if (current->n < current->prev->n)
			{
				swap_node_after(list, &tail, &current);
				print_list((const listint_t *)*list);
				shook = 0;
			}
			current = current->prev;
		}
	}
}

/**
 * swap_node_before - swaps the current node's pointers with the one
 * before it in the linked list
 *
 * @list: linked list
 * @tail: double pointer to the last node
 * @current: current node
 */
void swap_node_before(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*current)->prev;
	(*current)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}

/**
 * swap_node_after - swaps the current node's pointers with the one
 * after it in the linked list
 *
 * @list: linked list
 * @tail: double pointer to the last node
 * @current: current node
 */
void swap_node_after(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*current)->next;
	(*current)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}
