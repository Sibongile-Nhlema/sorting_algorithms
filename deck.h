#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <stdio.h>

/**
 * enum kind_e - Card type
 *
 * @SPADE: Spade
 * @HEART: Heart
 * @CLUB: Club
 * @DIAMOND: Diamond
*/
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * struct card_value_s - Card values
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @id: The id of a value
 */
typedef struct card_value_s
{
	const char *value;
	int id;
} card_value_t;

void sort_deck(deck_node_t **deck);

#define DECK_SIZE 52

#endif
