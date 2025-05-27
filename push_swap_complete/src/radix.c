
#include "push_swap.h"
#include <stdlib.h>

static int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void assign_index(t_stack *a) {
    int size = stack_size(a);
    int *array = stack_to_array(a);

    qsort(array, size, sizeof(int), compare_ints);

    t_node *node = a->top;
    while (node) {
        int i = 0;
        while (i < size) {
            if (node->value == array[i]) {
                node->index = i;
                break;
            }
            i++;
        }
        node = node->next;
    }
    free(array);
}

int *stack_to_array(t_stack *a) {
    int size = stack_size(a);
    int *array = malloc(sizeof(int) * size);
    if (!array)
        return NULL;

    t_node *tmp = a->top;
    int i = 0;
    while (i < size && tmp) {
        array[i] = tmp->value;
        tmp = tmp->next;
        i++;
    }
    return array;
}

void radix_sort(t_stack *a, t_stack *b) {
    int size = stack_size(a);
    int max_bits = 0;
    int tmp = size - 1;

    while (tmp >> max_bits)
        max_bits++;

    int i = 0;
    while (i < max_bits) {
        int j = 0;
        int count = 0;
        while (count < size) {
            if (((a->top->index >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            count++;
        }
        while (!is_empty(b))
            pa(b, a);
        i++;
    }
}
