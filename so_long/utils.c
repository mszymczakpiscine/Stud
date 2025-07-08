/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:31:52 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/05 15:57:17 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;

	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->window.ptr);
		free_map(game->map);
		exit(0);
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
	if (game->map[new_y * game->width + new_x] != TILE_WALL)
	{
		game->steps++;
		if (game->map[new_y * game->width + new_x] == TILE_ITEM)
		{
			game->collected++;
			game->map[new_y * game->width + new_x] = TILE_EMPTY;
		}
		if (game->map[new_y * game->width + new_x] == TILE_EXIT)
		{
			if (game->collected == game->collectibles)
			{
				write(1, "You win!\n", 9);
				mlx_destroy_window(game->mlx, game->window.ptr);
				free_map(game->map);
				exit(0);
			}
			return (0);
		}

		game->player_x = new_x;
		game->player_y = new_y;
		printf("Steps: %d\n", game->steps);
	}
	return (0);
}

int	render_frame(t_game *game)
{
	int	x;
	int	y;
	//int	i;
	int	pos;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			pos = y * game->width + x;
			mlx_put_image_to_window(game->mlx, game->window.ptr,
				game->floor.data, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[pos] == TILE_WALL)
				mlx_put_image_to_window(game->mlx, game->window.ptr,
					game->wall.data, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[pos] == TILE_ITEM)
				mlx_put_image_to_window(game->mlx, game->window.ptr,
					game->collect.data, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[pos] == TILE_EXIT)
				mlx_put_image_to_window(game->mlx, game->window.ptr,
					game->exit.data, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window.ptr,
		game->player.data, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	return (0);
}
