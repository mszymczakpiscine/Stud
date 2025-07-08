/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:28:01 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/05 15:28:03 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	char_to_tile(char c)
{
	if (c == '0')
		return (TILE_EMPTY);
	if (c == '1')
		return (TILE_WALL);
	if (c == 'C')
		return (TILE_ITEM);
	if (c == 'E')
		return (TILE_EXIT);
	if (c == 'P')
		return (TILE_START);
	return (TILE_INVALID);
}

int	count_line(char *file)
{
	int		fd;
	int		line = 0;
	char	c;
	int		val_return;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((val_return = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			line++;
	}
	close(fd);
	return (line);
}

int	tile_count(char *file)
{
	int		fd;
	int		count = 0;
	char	c;
	t_tile	tile;
	int		val_return;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((val_return = read(fd, &c, 1)) > 0)
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

int	col_count(char *file)
{
	int		fd;
	int		col = 0;
	int		first_line = -1;
	char	c;
	int		val_return;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((val_return = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
		{
			if (first_line == -1)
				first_line = col;
			else if (col != first_line)
				return (close(fd), -1);
			col = 0;
			continue;
		}
		col++;
	}
	close(fd);
	return (first_line);
}

void	print_map(t_tile *map, int width, int height)
{
	char	c;
	int		y, x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y * width + x] == TILE_WALL)
				c = '1';
			else if (map[y * width + x] == TILE_START)
				c = 'P';
			else if (map[y * width + x] == TILE_EXIT)
				c = 'E';
			else if (map[y * width + x] == TILE_ITEM)
				c = 'C';
			else
				c = '0';
			printf("%c", c);
			x++;
		}
		printf("\n");
		y++;
	}
}
