
#include "push_swap.h"

void sort_two(t_stack *a) {
    if (a->top->value > a->top->next->value)
        sa(a);
}

void sort_three(t_stack *a) {
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

void push_smallest(t_stack *a, t_stack *b) {
    t_node *tmp = a->top;
    int min = tmp->value;
    int pos = 0, i = 0;
    while (tmp) {
        if (tmp->value < min) {
            min = tmp->value;
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    while (pos-- > 0)
        ra(a);
    pb(a, b);
}

void sort_five(t_stack *a, t_stack *b) {
    push_smallest(a, b);
    if (stack_size(a) == 4)
        push_smallest(a, b);
    sort_three(a);
    pa(b, a);
    if (stack_size(b))
        pa(b, a);
}
