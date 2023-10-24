#include "sort.h"

/**
 * get_maximum - Get the max val in an array of ints.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Return: The max int in the array.
 */
int get_maximum(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of ints in asc order
 *                 using the counting sort algo.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after its set up.
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *is_sorted, maximum, i;

	if (array == NULL || size < 2)
		return;

	is_sorted = malloc(sizeof(int) * size);
	if (is_sorted == NULL)
		return;
	maximum = get_maximum(array, size);
	counter = malloc(sizeof(int) * (maximum + 1));
	if (counter == NULL)
	{
		free(is_sorted);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		counter[i] += counter[i - 1];
	print_array(counter, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		is_sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = is_sorted[i];

	free(is_sorted);
	free(counter);
}
