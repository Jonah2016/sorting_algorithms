#include "sort.h"

/**
 * integers_swapper - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void integers_swapper(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sort an array of ints in ascending
 *              order using the shell sort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Uses Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t space, i, k;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			k = i;
			while (k >= space && array[k - space] > array[k])
			{
				integers_swapper(array + k, array + (k - space));
				k -= space;
			}
		}
		print_array(array, size);
	}
}
