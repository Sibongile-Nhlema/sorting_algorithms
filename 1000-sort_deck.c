#include "deck.h"

/**
 * compare_cards - Compares two cards based on their
 * suits (kinds) and values.
 *
 * @a: A pointer to the first card
 * @b: A pointer to the second card
 *
 * Return: The difference between the card's kinds or values
*/
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;
	int a_value, b_value;
	char value_a_char;
	char value_b_char;

	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);

	value_a_char = node_a->card->value[0];
	a_value = (value_a_char >= '2' && value_a_char <= '9') ? value_a_char - '0'
	: (value_a_char == '1') ? 10
	: (value_a_char == 'A') ? 1
	: (value_a_char == 'J') ? 11
	: (value_a_char == 'Q') ? 12
	: (value_a_char == 'K') ? 13
	: 0;

	value_b_char = node_b->card->value[0];
	b_value = (value_b_char >= '2' && value_b_char <= '9') ? value_b_char - '0'
	: (value_b_char == '1') ? 10
	: (value_b_char == 'A') ? 1
	: (value_b_char == 'J') ? 11
	: (value_b_char == 'Q') ? 12
	: (value_b_char == 'K') ? 13
	: 0;

	return (a_value - b_value);

}

/**
 * sort_deck - Sorts a deck of cards, in ascending order
 *
 * @deck: A pointer to a pointer pointing to the first card
 * in the deck
*/
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	deck_node_t *node_array[DECK_SIZE];
	size_t i;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	current = *deck;
	for (i = 0; i < DECK_SIZE; i++)
	{
		node_array[i] = current;
		current = current->next;
	}

	qsort(node_array, DECK_SIZE, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < DECK_SIZE; i++)
	{
		if (i == 0)
		{
			*deck = node_array[i];
			node_array[i]->prev = NULL;
		}
		else
		{
			node_array[i - 1]->next = node_array[i];
			node_array[i]->prev = node_array[i - 1];
		}

		if (i == DECK_SIZE - 1)
		{
			node_array[i]->next = NULL;
		}
		else
		{
			node_array[i]->next = node_array[i + 1];
		}
	}
}
