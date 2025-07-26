/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:39:28 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:44:05 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *map_file)
{
	if (check_map_dimensions(game, map_file))
		return (1);
	game->collected = 0;
	game->steps = 0;
	game->frame_count = 0;
	if (load_game_map(game, map_file))
		return (1);
	return (0);
}

int	init_window_and_images(t_game *game)
{
	game->window.ptr = mlx_new_window(game->mlx,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"so_long");
	if (!game->window.ptr)
	{
		free_map(game->map);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (1);
	}
	load_images(game);
	count_collectibles(game);
	return (0);
}

static int	check_validity_and_copy(t_game *game, t_check *map, char *map_file)
{
	if (!validate_map(game->map, game->width, game->height))
	{
		write(2, "Error\nInvalid map.\n", 20);
		if (game->mlx)
			end_game(game);
		free(map);
		return (1);
	}
	if (!copy_map_check(game, map, map_file))
	{
		free(map);
		return (1);
	}
	flood_fill(map, game->player_x, game->player_y);
	if (check_after_filled(map->map))
	{
		free_check_map(map);
		end_game(game);
		if (game->mlx)
			return (1);
	}
	return (0);
}

int	start_game(t_game *game, char *map_file)
{
	t_check	*map;

	map = ft_calloc(1, sizeof(t_check));
	if (!map)
		return (1);
	if (init_game(game, map_file))
	{
		free(map);
		return (1);
	}
	if (init_window_and_images(game))
	{
		free(map);
		return (1);
	}
	init_enemy_position(game);
	game->enemy_dir = 0;
	if (check_validity_and_copy(game, map, map_file))
		return (1);
	free_check_map(map);
	return (0);
}
