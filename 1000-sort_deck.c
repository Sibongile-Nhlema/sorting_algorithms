#include "deck.h"

/**
 *  sort_deck - sorts a deck of cards
 *  @deck: double pointer the linked list containing the cards
 */
void sort_deck(deck_node_t **deck)
{
	/*sort cards into new lists*/
	deck_node_t *spade_head = NULL;
	deck_node_t *club_head = NULL;
	deck_node_t *diamond_head = NULL;
	deck_node_t *heart_head = NULL;
	deck_node_t *current;
	deck_node_t *new_node;

	current = *deck;
	while (current != NULL)
	{
		new_node = malloc(sizeof(deck_node_t));
		if (new_node == NULL)
			return;

		new_node->card = current->card;
		new_node->prev = NULL;
		new_node->next = NULL;

		switch (current->card->kind)
		{
			case SPADE:
				if (spade_head == NULL)
					spade_head = new_node;
				else
				{
					new_node->next = spade_head;
					spade_head->prev = new_node;
					spade_head = new_node;
				}
				break;
			case CLUB:
				if (club_head == NULL)
					club_head = new_node;
				else
				{
					new_node->next = club_head;
					club_head->prev = new_node;
					club_head = new_node;
				}
				break;
			case DIAMOND:
				if (diamond_head == NULL)
					diamond_head = new_node;
				else
				{
					new_node->next = diamond_head;
					diamond_head->prev = new_node;
					diamond_head = new_node;
				}
				break;
			case HEART:
				if (heart_head == NULL)
					heart_head = new_node;
				else
				{
					new_node->next = heart_head;
					heart_head->prev = new_node;
					heart_head = new_node;
				}
				break;
		}
		current = current->next;
	}
	printf("Spade: ");
	print_deck(spade_head);
	printf("\n");

	printf("Club: ");
	print_deck(club_head);
	printf("\n");

	printf("Diamond: ");
	print_deck(diamond_head);
	printf("\n");

	printf("Heart: ");
	print_deck(heart_head);
	printf("\n");

	/*sort each list*/
	/*merge all lists*/
}
