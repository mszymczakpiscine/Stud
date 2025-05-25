
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_node {
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

t_stack *init_stack(int argc, char **argv);
void free_stack(t_stack *stack);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *b, t_stack *a);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
void sort_two(t_stack *a);
void sort_three(t_stack *a);
void sort_five(t_stack *a, t_stack *b);
void push_smallest(t_stack *a, t_stack *b);
void assign_index(t_stack *a);
void radix_sort(t_stack *a, t_stack *b);
int stack_size(t_stack *a);
bool is_empty(t_stack *stack);
int *stack_to_array(t_stack *a);

#endif
