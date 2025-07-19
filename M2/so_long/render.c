/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:22:25 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/19 11:41:43 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, t_img img, int x, int y)
{
	mlx_put_image_to_window(
		game->mlx,
		game->window.ptr,
		img.data,
		x * TILE_SIZE,
		y * TILE_SIZE
	);
}

void	render_map(t_game *game)
{
	int	x, y;
	t_tile	tile;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y * game->width + x];
			put_tile(game, game->floor, x, y);
			if (tile == TILE_WALL)
				put_tile(game, game->wall, x, y);
			else if (tile == TILE_ITEM)
				put_tile(game, game->collect, x, y);
			else if (tile == TILE_EXIT)
				put_tile(game, game->exit, x, y);
			x++;
		}
		y++;
	}
	put_tile(game, game->player, game->player_x, game->player_y);
}
