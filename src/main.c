/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:06:55 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/25 15:06:57 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv) {
    if (argc < 2)
        return 1;
    t_stack *a = init_stack(argc, argv);
    t_stack *b = malloc(sizeof(t_stack));
    b->top = NULL;
    assign_index(a);
    int size = stack_size(a);
    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
        radix_sort(a, b);
    free_stack(a);
    free_stack(b);
    return 0;
}
