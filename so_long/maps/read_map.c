/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:06:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/18 12:19:02 by mszymcza         ###   ########.fr       */
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
	char	c;
	int		val_return;

	count_col = 0;
	fd =  open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		val_return = read(fd, &c, 1);
		if (val_return <= 0)
			break ;
		if (c == '\n')
			//faire autre chose
			return (close(fd), count_col);
		count_col++;
	}
	close(fd);
	return (count_col);
}

t_tile	*read_map(char *file_in)
{
	int		fd;
	char	*line;
	t_tile	*map;
	int		tile = tile_count( file_in);
	int		height = count_line(file_in);
	int		col;

	map = malloc(sizeof(t_tile) * tile);
	if (!map)
		return (NULL);
	
	
	

	
	//bouleen (tab[][])
	//parsing
	//lire tab[] allocation dyamique pour avoir la size officielle
	//fichier pour size
	// verif si 0 ou 1 (good ou pas good chaque critere)
	// si good open la bonne size de map else ERROR 
	// une fois read, close
	//free touuuuuut <3
	
	
}

