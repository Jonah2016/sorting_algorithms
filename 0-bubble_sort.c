#include "sort.h"

/**
 * integers_swapper - Swaps two ints in an array.
 * @a: The 1st integer to swaps.
 * @b: The 2nd integer to swaps.
 */
void integers_swapper(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool is_bubble = false;

	if (array == NULL || size < 2)
		return;

	while (is_bubble == false)
	{
		is_bubble = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				integers_swapper(array + i, array + i + 1);
				print_array(array, size);
				is_bubble = false;
			}
		}
		len--;
	}
}

