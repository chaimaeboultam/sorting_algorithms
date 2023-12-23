#include "sort.h"

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
    int pivot, temp;
    size_t i, j;

    pivot = array[high];
    i = low;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            /* Swap elements if they are in the wrong order */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            /* Print the array after each swap */
            print_array(array, size);

            i++;
        }
    }

    /* Swap the pivot element to its correct position */
    temp = array[i];
    array[i] = array[high];
    array[high] = temp;

    /* Print the array after each swap */
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
    size_t pivot;

    if (low < high)
    {
        /* Find pivot and partition the array */
        pivot = lomuto_partition(array, low, high, size);

        /* Recursively sort the sub-arrays */
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
