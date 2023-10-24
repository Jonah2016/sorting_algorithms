#include "sort.h"

/**
 * nodes_swapper - Swaps 2 nodes in a listint_t doubly-linked list.
 * @h: A pntr to the head of the doubly-linked list.
 * @n1: A pntr to the first node to swaps.
 * @n2: The 2nd node to swaps.
 */
void nodes_swapper(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *input, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterator = (*list)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		input = iterator->prev;
		while (input != NULL && iterator->n < input->n)
		{
			nodes_swapper(list, &input, iterator);
			print_list((const listint_t *)*list);
		}
	}
}
