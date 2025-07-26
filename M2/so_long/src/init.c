/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:36:48 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:13:11 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_images(t_game *game)
{
	if (!game->enemy.data)
	{
		write(2, "Error\nEnemy sprite not found.\n", 30);
		close_game(game);
	}
	if (!game->player.data || !game->wall.data || !game->floor.data
		|| !game->collect.data || !game->exit.data)
	{
		write(2, "Error\nFailed to load one or more images.\n", 41);
		if (game->player.data)
			mlx_destroy_image(game->mlx, game->player.data);
		if (game->wall.data)
			mlx_destroy_image(game->mlx, game->wall.data);
		if (game->floor.data)
			mlx_destroy_image(game->mlx, game->floor.data);
		if (game->collect.data)
			mlx_destroy_image(game->mlx, game->collect.data);
		if (game->exit.data)
			mlx_destroy_image(game->mlx, game->exit.data);
		if (game->enemy.data)
			mlx_destroy_image(game->mlx, game->enemy.data);
		end_game(game);
	}
}

void	load_images(t_game *game)
{
	int	size;

	size = TILE_SIZE;
	game->player.data = mlx_xpm_file_to_image
		(game->mlx, "assets/player.xpm", &size, &size);
	game->wall.data = mlx_xpm_file_to_image
		(game->mlx, "assets/wall.xpm", &size, &size);
	game->floor.data = mlx_xpm_file_to_image
		(game->mlx, "assets/floor.xpm", &size, &size);
	game->collect.data = mlx_xpm_file_to_image
		(game->mlx, "assets/collectible.xpm", &size, &size);
	game->exit.data = mlx_xpm_file_to_image
		(game->mlx, "assets/exit.xpm", &size, &size);
	game->enemy.data = mlx_xpm_file_to_image
		(game->mlx, "assets/enemy.xpm", &size, &size);
	check_images(game);
}

void	count_collectibles(t_game *game)
{
	int	i;

	i = 0;
	game->collectibles = 0;
	while (i < game->width * game->height)
	{
		if (game->map[i] == TILE_ITEM)
			game->collectibles++;
		i++;
	}
}

int	check_map_dimensions(t_game *game, char *map_file)
{
	game->height = count_line(map_file);
	game->width = col_count(map_file);
	if (game->height <= 0 || game->width <= 0)
	{
		write(2, "Error\nInvalid map dimensions.\n", 30);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		return (1);
	}
	return (0);
}

int	load_game_map(t_game *game, char *map_file)
{
	game->map = read_map(map_file, game->width, game->height, game);
	if (!game->map)
	{
		write(2, "Map not loaded, skipping enemy init\n", 35);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		return (1);
	}
	return (0);
}
