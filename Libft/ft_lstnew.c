/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:53:41 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/12 14:53:41 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elemt;

	elemt = (t_list *)malloc(sizeof(t_list));
	if (!elemt)
		return (NULL);
	elemt->content = content;
	elemt->next = NULL;
	return (elemt);
}
