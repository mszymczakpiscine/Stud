
#include "push_swap.h"

int stack_size(t_stack *a) {
    int size = 0;
    t_node *tmp = a->top;
    while (tmp) {
        size++;
        tmp = tmp->next;
    }
    return size;
}

bool is_empty(t_stack *stack) {
    return !stack->top;
}
