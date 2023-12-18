#include "deck.h"

void insertion_sort(card_t **cards, int size);
int compare_cards(const void *card1, const void *card2);
int custom_strcmp(const char *str1, const char *str2);
/**
 *  sort_deck - sorts a deck of cards
 *  @deck: double pointer the linked list containing the cards
 *
 *  Description: orders from Ace to King then Spades to Diamonds
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current = *deck;
	card_t *cards[52];
	int i = 0;

	while (current != NULL)
	{
		cards[i] = (card_t *)current->card;
		current = current->next;
		i++;
	}

	qsort(cards, 52, sizeof(card_t *), compare_cards);
	insertion_sort(cards, 52);

	current = *deck;
	i = 0;
	while (current != NULL)
	{
		current->card = cards[i];
		current = current->next;
		i++;
	}
}

/**
 * compare_cards - compares the value and kind of each card against the next
 * @card1: first card
 * @card2: second card
 * Return: the difference betwween the two kinds
 */
int compare_cards(const void *card1, const void *card2)
{
	int i, index1, index2;
	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;
	const char *card_values[] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	/* Get the indices of the card values in the desired order*/
	index1 = -1;
	index2 = -1;
	for (i = 0; i < 13; i++)
	{
		if (custom_strcmp(c1->value, card_values[i]) == 0)
			index1 = i;
		if (custom_strcmp(c2->value, card_values[i]) == 0)
			index2 = i;
	}
	/* Compare the indices of the card values */
	if (index1 != index2)
		return (index1 - index2);

	return (c1->kind - c2->kind);
}

/**
 * custom_strcmp - compares two strings
 * @str1: fisrt string
 * @str2: second string
 * Return:  an integer indicating the order of the strings
 */
int custom_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * insertion_sort - sorts the linked list using the insertion sort algorithm
 * @cards: double pointer to the linked list
 * @size: the size of the linked list
 */
void insertion_sort(card_t **cards, int size)
{
	card_t *suit_key;
	int j, k;

	for (j = 1; j < size; j++)
	{
		suit_key = cards[j];
		k = j - 1;
		while (k >= 0 && cards[k]->kind > suit_key->kind)
		{
			cards[k + 1] = cards[k];
			k--;
		}
		cards[k + 1] = suit_key;
	}
}
