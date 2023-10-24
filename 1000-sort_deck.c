#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char value_getter(deck_node_t *card);
void input_sort_deck_type(deck_node_t **deck);
void input_sort_deck_val(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings values.
 * @s1: The 1st strn vals to be compared.
 * @s2: The 2nd strn vals to be compared.
 *
 * Return: Positive (+) byte diff if s1 > s2
 *         0 if s1 == s2
 *         Negative (-) byte diff if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * value_getter - Get the numerical val of a card.
 * @card: A pntr to a deck_node_t card.
 *
 * Return: The numerical val of the card.
 */
char value_getter(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * input_sort_deck_type - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void input_sort_deck_type(deck_node_t **deck)
{
	deck_node_t *iterator, *input, *temp;

	for (iterator = (*deck)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		input = iterator->prev;
		while (input != NULL && input->card->kind > iterator->card->kind)
		{
			input->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = input;
			iterator->prev = input->prev;
			iterator->next = input;
			if (input->prev != NULL)
				input->prev->next = iterator;
			else
				*deck = iterator;
			input->prev = iterator;
			input = iterator->prev;
		}
	}
}

/**
 * input_sort_deck_val - Sort a deck of cards sorted from
 *                       spades to diamonds from ace to king.
 * @deck: A pntr to the head of a deck_node_t doubly-linked list.
 */
void input_sort_deck_val(deck_node_t **deck)
{
	deck_node_t *iterator, *input, *temp;

	for (iterator = (*deck)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		input = iterator->prev;
		while (input != NULL &&
			   input->card->kind == iterator->card->kind &&
			   value_getter(input) > value_getter(iterator))
		{
			input->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = input;
			iterator->prev = input->prev;
			iterator->next = input;
			if (input->prev != NULL)
				input->prev->next = iterator;
			else
				*deck = iterator;
			input->prev = iterator;
			input = iterator->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	input_sort_deck_type(deck);
	input_sort_deck_val(deck);
}
