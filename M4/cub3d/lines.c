/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:12:55 by aheisch           #+#    #+#             */
/*   Updated: 2025/11/03 14:12:55 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_lines	lines_new(int fd)
{
	return ((t_lines){fd, NULL, NULL});
}

void	lines_destroy(t_lines *lines)
{
	while (lines_next(lines))
		;
	if (lines->fd >= 0)
		close(lines->fd);
	free(lines->peek);
	free(lines->last);
	lines->fd = -1;
	lines->peek = NULL;
	lines->last = NULL;
}

static char	*get_next(t_lines *lines)
{
	free(lines->last);
	lines->last = ft_get_next_line(lines->fd);
	if (!lines->last)
	{
		close(lines->fd);
		lines->fd = -1;
	}
	return (lines->last);
}

char	*lines_next(t_lines *lines)
{
	if (lines->peek)
	{
		free(lines->last);
		lines->last = lines->peek;
		lines->peek = NULL;
		return (lines->last);
	}
	if (lines->fd >= 0)
		return (get_next(lines));
	return (NULL);
}

char	*lines_peek(t_lines *lines)
{
	if (!lines->peek)
	{
		lines->peek = get_next(lines);
		lines->last = NULL;
	}
	return (lines->peek);
}
