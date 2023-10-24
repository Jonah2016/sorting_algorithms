#include "sort.h"

void sub_array_merger(int *sub_arr, int *buff, size_t front, size_t mid,
					  size_t back);
void recursive_merge_sorter(int *sub_arr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * sub_array_merger - Sort a subarray of integers.
 * @sub_arr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void sub_array_merger(int *sub_arr, int *buff, size_t front, size_t mid,
					  size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_arr + front, mid - front);

	printf("[right]: ");
	print_array(sub_arr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (sub_arr[i] < sub_arr[j]) ? sub_arr[i++] : sub_arr[j++];
	for (; i < mid; i++)
		buff[k++] = sub_arr[i];
	for (; j < back; j++)
		buff[k++] = sub_arr[j];
	for (i = front, k = 0; i < back; i++)
		sub_arr[i] = buff[k++];

	printf("[Done]: ");
	print_array(sub_arr + front, back - front);
}

/**
 * recursive_merge_sorter - Uses merge sort algo through recursion.
 * @sub_arr: A sub_array of an array of ints to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the sub_array.
 * @back: The back index of the sub_array.
 */
void recursive_merge_sorter(int *sub_arr, int *buff, size_t front, size_t back)
{
	size_t center;

	if (back - front > 1)
	{
		center = front + (back - front) / 2;
		recursive_merge_sorter(sub_arr, buff, front, center);
		recursive_merge_sorter(sub_arr, buff, center, back);
		sub_array_merger(sub_arr, buff, front, center, back);
	}
}

/**
 * merge_sort - Sort an array of ints in asc
 *              order using the merge sort algo.
 * @array: An arr of ints.
 * @size: The size of the array.
 *
 * Description: uses the top-down merge sort algo approach.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	recursive_merge_sorter(array, buff, 0, size);

	free(buff);
}

