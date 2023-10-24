/*
 * File: 106-bitonic_sort.c
 * Auth: Jonah Etuaful and Stephen Amponsah
 */

#include "sort.h"

void integers_swapper(int *a, int *b);
void bitonic_merger(int *array, size_t size, size_t start, size_t seq,
					char flow);
void bitonic_sequence(int *array, size_t size, size_t start,
		size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * integers_swapper - Swap two ints in an array.
 * @a: The 1st int to swap.
 * @b: The 2nd int to swap.
 */
void integers_swapper(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merger - Sort a bitonic seq inside an array of ints.
 * @array: An array of ints.
 * @size: The size of the array.
 * @start: begining index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merger(int *array, size_t size, size_t start, size_t seq,
					char flow)
{
	size_t i, escape = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + escape; i++)
		{
			if ((flow == UP && array[i] > array[i + escape]) ||
				(flow == DOWN && array[i] < array[i + escape]))
				integers_swapper(array + i, array + i + escape);
		}
		bitonic_merger(array, size, start, escape, flow);
		bitonic_merger(array, size, start + escape, escape, flow);
	}
}

/**
 * bitonic_sequence - Convert an array of ints into a bitonic seq.
 * @array: An array of ints.
 * @size: The size of the array.
 * @start: starting index of a block of the building bitonic seq.
 * @seq: The size of a block of the building bitonic seq.
 * @flow: The direction to sort the bitonic seq block in.
 */
void bitonic_sequence(int *array, size_t size, size_t start,
		size_t seq, char flow)
{
	size_t extract = seq / 2;
	char *strn = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, strn);
		print_array(array + start, seq);

		bitonic_sequence(array, size, start, extract, UP);
		bitonic_sequence(array, size, start + extract, extract, DOWN);
		bitonic_merger(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, strn);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of ints in asc
 *                order using the bitonic sort algo.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2**k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}
