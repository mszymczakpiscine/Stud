
#include "push_swap.h"

void ra(t_stack *a) {
    if (!a->top || !a->top->next) return;
    t_node *first = a->top;
    t_node *tmp = a->top;
    while (tmp->next)
        tmp = tmp->next;
    a->top = first->next;
    first->next = NULL;
    tmp->next = first;
    write(1, "ra\n", 3);
}
