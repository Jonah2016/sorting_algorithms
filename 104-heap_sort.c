#include "sort.h"

void integers_swapper(int *a, int *b);
void maximum_heapifier(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * integers_swapper - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void integers_swapper(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * maximum_heapifier - Turns a binary tree into a complete binary heap.
 * @array: An array of ints representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void maximum_heapifier(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, huge;

	left = 2 * root + 1;
	right = 2 * root + 2;
	huge = root;

	if (left < base && array[left] > array[huge])
		huge = left;
	if (right < base && array[right] > array[huge])
		huge = right;

	if (huge != root)
	{
		integers_swapper(array + root, array + huge);
		print_array(array, size);
		maximum_heapifier(array, size, base, huge);
	}
}

/**
 * heap_sort - Sort an array of ints in asc
 *             order using the heap sort algo.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Uses the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		maximum_heapifier(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		integers_swapper(array, array + i);
		print_array(array, size);
		maximum_heapifier(array, size, i, 0);
	}
}

