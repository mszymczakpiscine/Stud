/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:55:09 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 10:55:41 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line(int col, int *first)
{
	if (*first == -1)
	{
		*first = col;
		return (1);
	}
	return (col == *first);
}

static int	handle_char(char c, int *col, int *first)
{
	if (c == '\n')
	{
		if (!check_line(*col, first))
			return (-1);
		*col = 0;
	}
	else
		(*col)++;
	return (1);
}

static int	read_loop(int fd, int *first)
{
	char	c;
	int		col;
	int		ret;

	col = 0;
	ret = read(fd, &c, 1);
	while (ret > 0)
	{
		if (handle_char(c, &col, first) == -1)
			return (-1);
		ret = read(fd, &c, 1);
	}
	if (*first == -1)
		return (col);
	return (*first);
}

int	col_count(char *file)
{
	int	fd;
	int	first;
	int	result;

	first = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	result = read_loop(fd, &first);
	close(fd);
	return (result);
}
