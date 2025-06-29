/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:18:02 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/29 10:17:48 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_line(char *file)
{
	int		fd;
	int		line;
	char	c;
	int		val_return;

	line = 0;
	fd =  open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		val_return = read(fd, &c, 1);
		if (val_return <= 0)
			break ;
		if (c == '\n')
			line++;
	}
	close(fd);
	return (line);
}

int	tile_count(char *file)
{
	int		fd;
	int		tile_count;
	char	c;
	t_tile	tile;
	int		val_return;

	tile_count = 0;
	fd =  open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		val_return = read(fd, &c, 1);
		if (val_return <= 0)
			break ;
		tile = char_to_tile(c);
		if (tile == TILE_INVALID)
			return (close(fd), -1);
		tile_count++;
	}
	close(fd);
	return (tile_count);
}

int	col_count(char *file)
{
	int		fd;
	int		count_col;
	int		first_line_cols = -1;
	char	c;
	int		val_return;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	
	count_col = 0;
	while (1)
	{
		val_return = read(fd, &c, 1);
		if (val_return <= 0)
			break;
		if (c == '\n')
		{
			if (first_line_cols == -1)
				first_line_cols = count_col;
			else if (count_col != first_line_cols)
				return (close(fd), -1);
			count_col = 0;
			continue;
		}
		count_col++;
	}
	close(fd);
	return (first_line_cols);
}
