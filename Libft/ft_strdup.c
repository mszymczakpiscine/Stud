/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:41:10 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/20 13:59:45 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
    char	*dest;
    size_t	i;

    dest = (char *) malloc(ft_strlen(s1) + 1);
    if (!dest)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}