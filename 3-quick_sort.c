#include "sort.h"

void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursively sorts an array of
 * integers using the Quicksort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the sub-array to be sorted
 * @high: The ending index of the sub-array to be sorted
 * @size: The size of the array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int i = lomuto(array, low, high, size);

		quick_sort_recursive(array, low, i - 1, size);
		quick_sort_recursive(array, i + 1, high, size);
	}
}

/**
 * lomuto - Partitions an array using the Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the sub-array to be partitioned
 * @high: The ending index of the sub-array to be partitioned
 * @size: The size of the array
 *
 * Return: The final index of the pivot element
 */

int lomuto(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		int temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}