/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:22:25 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/22 19:28:07 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, t_img img, int x, int y)
{
	if (!img.data)
		return;
	mlx_put_image_to_window(game->mlx, game->window.ptr, \
		 img.data, x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_tiles(t_game *game)
{
    int	x;
    int	y;
    int	pos;
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

	if (game->enemy.data &&
		game->enemy_x >= 0 && game->enemy_x < game->width &&
		game->enemy_y >= 0 && game->enemy_y < game->height)
	{
		put_tile(game, game->enemy, game->enemy_x, game->enemy_y);
	}
}


void	move_enemy(t_game *game)
{
	int	next_x = game->enemy_x;
	int	next_y = game->enemy_y;

	if (game->enemy_x == -1 || game->enemy_y == -1)
		return;
	if (game->enemy_x != -1 && game->enemy_y != -1)
	{
		mlx_put_image_to_window(game->mlx, game->window.ptr, \
			game->enemy.data, game->enemy_x * TILE_SIZE, \
			game->enemy_y * TILE_SIZE);
	}
	if (game->enemy_dir == 0)
		next_x++;
	else if (game->enemy_dir == 1)
		next_x--;
	else if (game->enemy_dir == 2)
		next_y++;
	else if (game->enemy_dir == 3)
		next_y--;
	char tile = game->map[next_y * game->width + next_x];
	if (tile == TILE_EMPTY || tile == TILE_FLOOR)
	{
		game->enemy_x = next_x;
		game->enemy_y = next_y;
	}
	else
	{
		game->enemy_dir = (game->enemy_dir + 1) % 4;
	}
}

int	render_frame(t_game *game)
{
	game->needs_redraw = 1;
    game->fps++;
	if (game->enemy_x == game->player_x && game->enemy_y == game->player_y)
    {
		write(1, "You died!\n", 10);
        close_game(game);
    }
	if (game->needs_redraw && game->fps % 4000 == 0)
	{
		render_map(game);
		put_steps_to_screen(game);
		game->needs_redraw = 1;
	}
	if (game->fps % 50000 == 0)
	{
		move_enemy_towards_player(game);
		game->needs_redraw = 1;
	}
	return (0);
}
