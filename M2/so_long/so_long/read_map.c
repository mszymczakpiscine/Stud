/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:06:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/29 10:15:12 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_tile *map)
{
	if (map)
		free(map);
}

t_tile	*read_map(char *file_in, int *width, int *height, t_game *game)
{
	int		fd;
	char	c;
	t_tile	*map;
	int		i = 0;
	int		val_return;

	*height = count_line(file_in);
	*width = col_count(file_in);
	if (*height <= 0 || *width <= 0)
		return (NULL);
	map = malloc(sizeof(t_tile) * (*width) * (*height));
	if (!map)
		return (NULL);
	fd = open(file_in, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
    while (i < (*width) * (*height) && (val_return = read(fd, &c, 1)) > 0) 
	{
        if (c == '\n') continue;
        map[i] = char_to_tile(c);
        if (map[i] == TILE_START) 
		{
            game->player_x = i % *width;
            game->player_y = i / *width;
        }
        if (map[i++] == TILE_INVALID)
            return (close(fd), free(map), NULL);
	}
	close(fd);
	return (map);
}

int	validate_map(t_tile *map, int width, int height)
{
	int	player;
	int	exit;
	int	collectibles;
	int	y;
	int	x;
	t_tile	tile;

	player = 0;
	exit = 0;
	collectibles = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			tile = map[y * width + x];
			if ((y == 0 || y == height - 1 || x == 0 || x == width - 1)
			 && tile != TILE_WALL)
				return (0);
			if (tile == TILE_START)
				player++;
			else if (tile == TILE_EXIT)
				exit++;
			else if (tile == TILE_ITEM)
				collectibles++;
			x++;
		}
		y++;
	}
	return (player == 1 && exit >= 1 && collectibles >= 1);
}

