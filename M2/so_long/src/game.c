/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:22:31 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:08:46 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	int	index;

	index = new_y * game->width + new_x;
	if (game->map[index] == TILE_WALL)
		return ;
	if (game->map[index] == TILE_ITEM)
	{
		game->collected++;
		game->map[index] = TILE_FLOOR;
	}
	if (game->map[index] == TILE_EXIT)
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("You win! Total steps: %d\n", game->steps + 1);
			exit(0);
		}
		else
			return ;
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->steps++;
	game->needs_redraw = 1;
	ft_printf("Steps: %d\n", game->steps);
}

void	move_player(t_game *game, int keycode)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_RIGHT)
		new_x++;
	else if (keycode == KEY_ESC)
	{
		ft_printf("Game exited.\n");
		exit(0);
	}
	update_player_position(game, new_x, new_y);
	game->needs_redraw = 1;
}
