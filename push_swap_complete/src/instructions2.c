
#include "push_swap.h"

void sb(t_stack *b) {
    if (!b->top || !b->top->next) return;
    t_node *first = b->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    b->top = second;
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b) {
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}
