
#include "push_swap.h"

void assign_index(t_stack *a) {
    int size = stack_size(a);
    int *array = stack_to_array(a);
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (t_node *node = a->top; node; node = node->next)
        for (int i = 0; i < size; i++)
            if (node->value == array[i])
                node->index = i;
    free(array);
}

int *stack_to_array(t_stack *a) {
    int size = stack_size(a);
    int *array = malloc(sizeof(int) * size);
    t_node *tmp = a->top;
    for (int i = 0; i < size; i++) {
        array[i] = tmp->value;
        tmp = tmp->next;
    }
    return array;
}

void radix_sort(t_stack *a, t_stack *b) {
    int size = stack_size(a);
    int max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    for (int i = 0; i < max_bits; i++) {
        for (int j = 0; j < size; j++) {
            if (((a->top->index >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
        }
        while (!is_empty(b))
            pa(b, a);
    }
}
