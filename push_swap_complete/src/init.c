
#include "push_swap.h"

t_node *new_node(int value) {
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->index = -1;
    node->next = NULL;
    return node;
}

void add_node(t_stack *stack, t_node *node) {
    node->next = stack->top;
    stack->top = node;
}

t_stack *init_stack(int argc, char **argv) {
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;

    stack->top = NULL;

    int i = argc - 1;
    while (i > 0) {
        int val = atoi(argv[i]);
        t_node *node = new_node(val);
        add_node(stack, node);
        i--;
    }

    return stack;
}

void free_stack(t_stack *stack) {
    t_node *tmp;
    while (stack->top) {
        tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
    free(stack);
}
