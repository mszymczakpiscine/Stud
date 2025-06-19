/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:05:42 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/28 18:02:33 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_el)
{
	t_list	*last;

	if (!lst || !new_el)
		return ;
	if (*lst == NULL)
	{
		*lst = new_el;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_el;
}
