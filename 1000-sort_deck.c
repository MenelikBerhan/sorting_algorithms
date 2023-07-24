#include "deck.h"
#include <string.h>

/**
 * comp_cards - compare two deck nodes. Cards are sorted from Ace to King
 * and from Spades to Diamonds.
 * @a: pointer to pointer to first node
 * @b: pointer to pointer to second node
 *
 * Return: a value less than, equal to or greater than 0 if a is
 * respectively less than, equal to or greater than b.
*/
int comp_cards(const void *a, const void *b)
{
	char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
		"Jack", "Queen", "King"};
	const deck_node_t *a_node, *b_node;
	int i;

	a_node = *(const deck_node_t **) a;
	b_node = *(const deck_node_t **) b;
	if (a_node->card->kind != b_node->card->kind)
		return (a_node->card->kind - b_node->card->kind);

	if (!strcmp(a_node->card->value, b_node->card->value))
		return (0);
	for (i = 0; i < 13; i++)
	{
		if (!strcmp(ranks[i], a_node->card->value))
			return (-1);
		if (!strcmp(ranks[i], b_node->card->value))
			return (1);
	}
	return (0);
}


/**
 * sort_deck - sorts a deck of cards using `C`'s `qsort`
 * @deck: doubly linked list with cards as nodes
 *
 */
void sort_deck(deck_node_t **deck)
{
	int i;
	deck_node_t *temp, *array[52];

	if (!deck || !(*deck) || !(*deck)->next)
		return;
	temp = *deck;
	for (i = 0; i < 52; i++)
	{
		array[i] = temp;
		temp = temp->next;
	}
	qsort(array, 52, sizeof(deck_node_t *), comp_cards);
	*deck = array[0];
	array[0]->prev = NULL;
	array[0]->next = array[1];
	for (i = 1; i < 51; i++)
	{
		array[i]->prev = array[i - 1];
		array[i]->next = array[i + 1];
	}
	array[51]->prev = array[50];
	array[51]->next = NULL;
}
