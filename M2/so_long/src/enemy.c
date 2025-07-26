/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:42:33 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:03:51 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (game->fps % 70000 == 0)
	{
		move_enemy_towards_player(game);
		game->needs_redraw = 1;
	}
	return (0);
}

static void	put_enemy(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->window.ptr,
		g->enemy.data, g->enemy_x * TILE_SIZE,
		g->enemy_y * TILE_SIZE);
}

static int	can_move(t_game *g, int x, int y)
{
	char	tile;

	tile = g->map[y * g->width + x];
	return (tile == TILE_EMPTY || tile == TILE_FLOOR);
}

void	move_enemy(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->enemy_x;
	next_y = game->enemy_y;
	if (game->enemy_x == -1 || game->enemy_y == -1)
		return ;
	put_enemy(game);
	if (game->enemy_dir == 0)
		next_x++;
	else if (game->enemy_dir == 1)
		next_x--;
	else if (game->enemy_dir == 2)
		next_y++;
	else if (game->enemy_dir == 3)
		next_y--;
	if (can_move(game, next_x, next_y))
	{
		game->enemy_x = next_x;
		game->enemy_y = next_y;
	}
	else
		game->enemy_dir = (game->enemy_dir + 1) % 4;
}
