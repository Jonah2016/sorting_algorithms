#include "sort.h"

void integers_swapper(int *a, int *b);
int hoare_partitioner(int *array, size_t size, int left, int right);
void hoare_sorter(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partitioner - Order a subset of an array of ints
 *                   according to the hoare partition scheme.
 * @array: The array of ints.
 * @size: The size of the array.
 * @left: beginning index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partitioning index.
 *
 * Description: Uses last element of the partition as the fulcrum.
 * Prints the array after each swap of two elements.
 */
int hoare_partitioner(int *array, size_t size, int left, int right)
{
	int fulcrum, top, down;

	fulcrum = array[right];
	for (top = left - 1, down = right + 1; top < down;)
	{
		do
		{
			top++;
		} while (array[top] < fulcrum);
		do
		{
			down--;
		} while (array[down] > fulcrum);

		if (top < down)
		{
			integers_swapper(array + top, array + down);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sorter - Uses the quicksort algo through recursion.
 * @array: An array of ints to sort.
 * @size: The size of the array.
 * @left: Beginning index of the array partition to order.
 * @right: ending index of the array partition to order.
 *
 * Description: Uses Hoare partition scheme technique.
 */
void hoare_sorter(int *array, size_t size, int left, int right)
{
	int section;

	if (right - left > 0)
	{
		section = hoare_partitioner(array, size, left, right);
		hoare_sorter(array, size, left, section - 1);
		hoare_sorter(array, size, section, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of ints in asc
 *                    order using the quicksort algo.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sorter(array, size, 0, size - 1);
}
