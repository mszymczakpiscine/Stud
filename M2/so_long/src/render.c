/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:22:25 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:42:36 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, t_img img, int x, int y)
{
	if (!img.data)
		return ;
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		img.data, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_tiles(t_game *game)
{
	int		x;
	int		y;
	int		pos;
	t_tile	tile;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			pos = y * game->width + x;
			tile = game->map[pos];
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
}

void	render_map(t_game *game)
{
	render_tiles(game);
	put_tile(game, game->player, game->player_x, game->player_y);
	if (game->enemy.data && game->enemy_x >= 0 && game->enemy_x < game->width
		&& game->enemy_y >= 0 && game->enemy_y < game->height)
		put_tile(game, game->enemy, game->enemy_x, game->enemy_y);
}
