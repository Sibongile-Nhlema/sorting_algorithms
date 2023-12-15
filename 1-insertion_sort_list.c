#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: A pointer to the pointer pointing to the first node
 * in a doubly linked list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/*Disconnect temp from previous and next nodes*/
			temp->prev->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			/*Swap temp and previous node*/
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			/**
			 * After swapping, if a node before temp exists,
			 * make its next pointer point to temp.
			 * If there's no node, then it's the head of the list.
			 */
			if (temp->prev != NULL)
			{
				temp->prev->next = temp;
			}
			else
			{
				*list = temp;
			}
			/*Make the next node's pointer point to temp*/
			temp->next->prev = temp;
			print_list(*list);
		}
		current = current->next;
	}
}
