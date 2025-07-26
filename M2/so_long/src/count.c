/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:44:42 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 10:55:31 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file)
{
	int		fd;
	int		line;
	char	c;
	int		val_return;

	line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	val_return = read(fd, &c, 1);
	while (val_return > 0)
	{
		if (c == '\n')
			line++;
		val_return = read(fd, &c, 1);
	}
	close(fd);
	return (line);
}

int	tile_count(char *file)
{
	int		fd;
	int		count;
	char	c;
	t_tile	tile;
	int		val_return;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	val_return = read(fd, &c, 1);
	while (val_return > 0)
	{
		tile = char_to_tile(c);
		if (tile == TILE_INVALID && c != '\n')
			return (close(fd), -1);
		if (c != '\n')
			count++;
	}
	close(fd);
	return (count);
}
