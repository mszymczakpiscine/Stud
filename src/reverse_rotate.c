
#include "push_swap.h"

void rra(t_stack *a) {
    if (!a->top || !a->top->next) return;
    t_node *prev = NULL;
    t_node *last = a->top;
    while (last->next) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = a->top;
    a->top = last;
    write(1, "rra\n", 4);
}
