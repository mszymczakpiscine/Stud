/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:31:52 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:45:30 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_item(t_game *game, int new_x, int new_y)
{
	game->collected++;
	game->map[new_y * game->width + new_x] = TILE_EMPTY;
}

static int	handle_exit(t_game *game)
{
	if (game->collected == game->collectibles)
	{
		write(1, "You win!\n", 9);
		mlx_loop_end(game->mlx);
	}
	return (0);
}

static void	update_player_pos(t_game *game, int new_x, int new_y)
{
	game->player_x = new_x;
	game->player_y = new_y;
	ft_printf("Steps: %d\n", game->steps);
}

static void	process_move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y * game->width + new_x] != TILE_WALL)
	{
		game->steps++;
		if (game->map[new_y * game->width + new_x] == TILE_ITEM)
			handle_item(game, new_x, new_y);
		if (game->map[new_y * game->width + new_x] == TILE_EXIT)
		{
			handle_exit(game);
			return ;
		}
		update_player_pos(game, new_x, new_y);
	}
}

int	handle_input(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(game->mlx);
	}
	if (keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_RIGHT)
		new_x++;
	else
		return (0);
	process_move(game, new_x, new_y);
	return (0);
}
