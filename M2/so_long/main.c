/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:40:21 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/19 11:41:30 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window.ptr);
	free_map(game->map);
	exit(0);
	return (0);
}

static void	load_images(t_game *game)
{
	int	size;

	size = TILE_SIZE;
	game->player.data = mlx_xpm_file_to_image \
		(game->mlx, "assets/player.xpm", &size, &size);
	game->wall.data = mlx_xpm_file_to_image \
		(game->mlx, "assets/wall.xpm", &size, &size);
	game->floor.data = mlx_xpm_file_to_image \
		(game->mlx, "assets/floor.xpm", &size, &size);
	game->collect.data = mlx_xpm_file_to_image \
		(game->mlx, "assets/collectible.xpm", &size, &size);
	game->exit.data = mlx_xpm_file_to_image \
		(game->mlx, "assets/exit.xpm", &size, &size);
	if (!game->player.data || !game->wall.data || !game->floor.data
		|| !game->collect.data || !game->exit.data)
	{
		write(2, "Error\nFailed to load one or more images.\n", 41);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map_file.ber>\n", 33);
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.height = count_line(argv[1]);
	game.width = col_count(argv[1]);
	game.collected = 0;
	game.steps = 0;
	game.map = read_map(argv[1], game.width, game.height, &game);
	if (!game.map || !validate_map(game.map, game.width, game.height))
	{
		write(2, "Error\nInvalid map.\n", 20);
		return (1);
	}
	game.window.ptr = mlx_new_window(game.mlx, game.width * TILE_SIZE,
			game.height * TILE_SIZE, "so_long");
	if (!game.window.ptr)
		return (free_map(game.map), 1);
	load_images(&game);
	game.collectibles = 0;
	i = 0;
	while (i < game.width * game.height)
	{
		if (game.map[i] == TILE_ITEM)
			game.collectibles++;
		i++;
	}
	mlx_key_hook(game.window.ptr, handle_input, &game);
	mlx_hook(game.window.ptr, 17, 0, (int (*)(void *))close_game, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
