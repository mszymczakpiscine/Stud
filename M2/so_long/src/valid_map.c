/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:48:36 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 12:30:20 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_tile_and_count(t_tile tile, t_counters *c)
{
	if (tile == TILE_START)
		c->player++;
	else if (tile == TILE_EXIT)
		c->exit++;
	else if (tile == TILE_ITEM)
		c->item++;
	return (1);
}

int	check_tiles(t_tile *map, int w, int h)
{
	int			x;
	int			y;
	t_counters	counters;
	t_map_size	size;

	size.w = w;
	size.h = h;
	counters.player = 0;
	counters.exit = 0;
	counters.item = 0;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if ((y == 0 || y == size.h - 1 || x == 0 || x == size.w - 1)
				&& map[y * w + x] != TILE_WALL)
				return (0);
			check_tile_and_count(map[y * w + x], &counters);
			x++;
		}
		y++;
	}
	return (counters.player == 1 && counters.exit >= 1 && counters.item >= 1);
}

int	validate_map(t_tile *map, int w, int h)
{
	if (w > MAX_MAP_WIDTH || h > MAX_MAP_HEIGHT)
	{
		write(2, "Error: map must not exceed 30 columns and 16 rows.\n", 52);
		return (0);
	}
	return (check_tiles(map, w, h));
}
