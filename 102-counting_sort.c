#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int max, *count, *output;
    size_t i;

    if (array == NULL || size < 2)
        return;

    max = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (i = 0; i <= (size_t)max; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[array[i]]++;

    print_count_array(count, max + 1);

    for (i = 1; i <= (size_t)max; i++)
        count[i] += count[i - 1];

    output = malloc(size * sizeof(int));
    if (output == NULL) {
        free(count);
        return;
    }

    for (i = size - 1; (int)i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    free(count);
}

/**
 * print_count_array - Prints the counting array.
 * @count: The counting array.
 * @size: The size of the array.
 */
void print_count_array(int *count, size_t size)
{
    size_t i;

    printf("%d", count[0]);
    for (i = 1; i < size; i++)
        printf(", %d", count[i]);
    printf("\n");
}
