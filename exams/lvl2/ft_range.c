/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:26:02 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/03 11:32:27 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int size;
	int *range;
	int i = 0;
	if (start <= end)
		size = end - start + 1;
	else 
		size = start - end + 1;
	range = malloc(sizeof(int) * size);
	if (!range)
		return NULL;
	if (start <= end)
	{
		while (start <= end)
			range[++i] = start++;
	}
	else 
	{
		while (start >= end)
			range[++i] = start--;
	}
	return range;
}

