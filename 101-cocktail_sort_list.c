#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 1;

    if (list == NULL || *list == NULL)
        return;

    while (swapped) {
        swapped = 0;
        /* Traverse from left to right */
        for (current = *list; current->next != NULL; current = current->next) {
            if (current->n > current->next->n) {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        /* Traverse from right to left */
        for (; current->prev != NULL; current = current->prev) {
            if (current->n < current->prev->n) {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list);
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head of the linked list.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
    if (a->prev != NULL)
        a->prev->next = b;
    else
        *list = b;

    if (b->next != NULL)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;
    a->prev = b;
    b->next = a;
}
