/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:33:28 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/03 11:38:57 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int i = 0;
	int size;
	int *range;
	if (start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;
	range = malloc(sizeof(int) * size);
	if (!range)
		return NULL;
	if (start <= end)
	{
		while (end >= start)
		{
				range[i] = end;
				end--;
				i++;
		}
	}
	else 
	{
		while (end <= start)
		{
				range[i] = end;
				end++;
				i++;
		}
	}
	return range;
}

