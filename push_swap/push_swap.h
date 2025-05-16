/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/16 11:51:32 by mszymcza         ###   ########.fr       */
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

/* Opérations de base sur les piles */
void		sa(t_stack *stack_a);           /* Swap les 2 premiers éléments de A */
void		sb(t_stack *stack_b);           /* Swap les 2 premiers éléments de B */
void		ss(t_stack *stack_a, t_stack *stack_b);  /* sa et sb en même temps */
void		pa(t_stack *stack_a, t_stack *stack_b);  /* Push de B vers A */
void		pb(t_stack *stack_a, t_stack *stack_b);  /* Push de A vers B */
void		ra(t_stack *stack_a);           /* Rotation vers le haut de A */
void		rb(t_stack *stack_b);           /* Rotation vers le haut de B */
void		rr(t_stack *stack_a, t_stack *stack_b);  /* ra et rb en même temps */
void		rra(t_stack *stack_a);          /* Rotation vers le bas de A */
void		rrb(t_stack *stack_b);          /* Rotation vers le bas de B */
void		rrr(t_stack *stack_a, t_stack *stack_b); /* rra et rrb en même temps */

/* Fonctions utilitaires */
t_stack		*init_stack(void);              /* Initialise une nouvelle pile */
void		free_stack(t_stack *stack);     /* Libère la mémoire d'une pile */
int			is_sorted(t_stack *stack);      /* Vérifie si la pile est triée */
void		add_node(t_stack *stack, int value); /* Ajoute un élément à la pile */
int			get_min(t_stack *stack);        /* Trouve la valeur minimale */
int			get_max(t_stack *stack);        /* Trouve la valeur maximale */
int			get_stack_size(t_stack *stack); /* Retourne la taille de la pile */

/* Gestion des erreurs et validation */
void		error_exit(t_stack *stack_a, t_stack *stack_b);
int			check_args(int argc, char **argv);
int			check_doubles(t_stack *stack);
long		ft_atoi(const char *str);       /* Version sécurisée de atoi */

/* Fonctions d'affichage pour le debug */
void		print_stack(t_stack *stack, char stack_name);

int			main(int argc, char **argv);

#endif 