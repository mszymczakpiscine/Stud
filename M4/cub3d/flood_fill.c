/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:40:20 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/31 13:40:20 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static t_tile	get_tile(t_game *game, size_t x, size_t y)
{
	return (game->map[y * game->width + x]);
}

static bool	is_empty(t_game *game, size_t x, size_t y)
{
	t_tile	tile;

	tile = get_tile(game, x, y);
	return (tile != TILE_SPACE && tile != TILE_WALL);
}

static bool	check_tile(t_game *game, size_t x, size_t y)
{
	if (!is_empty(game, x, y))
		return (false);
	if (y == 0 || x == 0)
		return (true);
	if (x + 1 >= (size_t)game->width || y + 1 >= (size_t)game->height)
		return (true);
	if (get_tile(game, x, y - 1) == TILE_SPACE)
		return (true);
	if (get_tile(game, x, y + 1) == TILE_SPACE)
		return (true);
	if (get_tile(game, x - 1, y) == TILE_SPACE)
		return (true);
	if (get_tile(game, x + 1, y) == TILE_SPACE)
		return (true);
	return (false);
}

bool	flood_fill(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)game->height)
	{
		x = 0;
		while (x < (size_t)game->width)
		{
			if (check_tile(game, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
