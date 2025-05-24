/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/24 11:37:32 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/* Structures */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* Opérations de base sur les piles (basics/) */
/* swap_operations.c */
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
/* push_operations.c */
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

/* rotate_operations.c */
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

/* reverse_rotate_operations.c */
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

/* Fonctions utilitaires (utils/) */
/* stack_utils.c */
t_stack		*init_stack(void);
void		free_stack(t_stack *stack);
int			is_sorted(t_stack *stack);
void		add_node(t_stack *stack, int value);
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			get_stack_size(t_stack *stack);

/* Gestion des erreurs et validation (errors_and_validations/) */
/* error_handling.c */
void		error_exit(t_stack *stack_a, t_stack *stack_b);

/* args_validation.c */
int			check_args(int argc, char **argv);
long		ft_atoi(const char *str);

/* stack_validation.c */
int			check_doubles(t_stack *stack);

/* Fonctions d'affichage pour le debug (debug/) */
/* print_stack.c */
void		print_stack(t_stack *stack, char stack_name);

/* Algorithmes de tri (sorting/) */
/* small_sort.c */
void		sort_small_stack(t_stack *stack_a, t_stack *stack_b);

/* big_sort.c */
void		sort_big_stack(t_stack *stack_a, t_stack *stack_b);

int			main(int argc, char **argv);

#endif 