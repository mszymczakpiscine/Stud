/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:27:35 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/22 15:25:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_tile *map)
{
	if (map)
		free(map); 
}

t_tile	*read_map(char *file_in, int width, int height, t_game *game)
{
    int		fd;
    char	c;
    t_tile	*map;
    int		i = 0;
    int		val_return;

    if (height <= 0 || width <= 0)
        return (NULL);
    map = malloc(sizeof(t_tile) * (width * height));
    if (!map)
        return (NULL);
    fd = open(file_in, O_RDONLY);
    if (fd < 0)
        return (free(map), NULL);
    while ((val_return = read(fd, &c, 1)) > 0)
    {
        if (c == '\n')
            continue;
        if (i >= width * height)
            break;
        map[i] = char_to_tile(c);
        if (map[i] == TILE_START)
        {
            game->player_x = i % width;
            game->player_y = i / width;
        }
        if (map[i] == TILE_INVALID)
            return (close(fd), free(map), NULL);
        i++;
    }
    close(fd);
    if (i != width * height)
        return (free(map), NULL);
    return (map);
}

int has_ber_extension(const char *filename)
{
    size_t len;

    len = strlen(filename);
    if (len < 5)
        return (0);
    return (strcmp(filename + len - 4, ".ber") == 0);
}

int	validate_map(t_tile *map, int width, int height)
{
	int	player = 0;
	int	exit = 0;
	int	collectibles = 0;
	int	y, x;
	t_tile	tile;

    if (width > MAX_MAP_WIDTH || height > MAX_MAP_HEIGHT)
    {
        write(2, "Error: map must not exceed 40 columns and 21 rows.\n", 52);
        return (0);
    }
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

