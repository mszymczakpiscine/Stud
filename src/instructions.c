
#include "push_swap.h"

void sa(t_stack *a) {
    if (!a->top || !a->top->next) return;
    t_node *first = a->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    a->top = second;
    write(1, "sa\n", 3);
}

void pa(t_stack *b, t_stack *a) {
    if (!b->top) return;
    t_node *tmp = b->top;
    b->top = b->top->next;
    tmp->next = a->top;
    a->top = tmp;
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b) {
    if (!a->top) return;
    t_node *tmp = a->top;
    a->top = a->top->next;
    tmp->next = b->top;
    b->top = tmp;
    write(1, "pb\n", 3);
}
