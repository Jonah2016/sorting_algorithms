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
 * selection_sort - Sort an array of ints in asc order
 *                  using the selection sort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min_val;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_val = array + i;
		for (j = i + 1; j < size; j++)
			min_val = (array[j] < *min_val) ? (array + j) : min_val;

		if ((array + i) != min_val)
		{
			integers_swapper(array + i, min_val);
			print_array(array, size);
		}
	}
}
