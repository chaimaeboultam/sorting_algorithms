#include "sort.h"

/**
 * swap - Swaps two integers in an array
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: Index of the pivot element after partitioning
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    size_t i = low;
    size_t j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            swap(&array[i], &array[j]);
            print_array(array, size);
            i++;
        }
    }

    swap(&array[i], &array[high]);
    print_array(array, size);

    return i;
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        size_t pivot = lomuto_partition(array, low, high, size);

        if (pivot > 0)
            quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
