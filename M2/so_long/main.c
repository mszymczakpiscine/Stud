/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:40:21 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/22 19:34:04 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}
void end_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	if(game->player.data)
		mlx_destroy_image(game->mlx, game->player.data);
	if(game->wall.data)
		mlx_destroy_image(game->mlx, game->wall.data);
	if(game->floor.data)
		mlx_destroy_image(game->mlx, game->floor.data);
	if(game->collect.data)
		mlx_destroy_image(game->mlx, game->collect.data);
	if(game->exit.data)
		mlx_destroy_image(game->mlx, game->exit.data);
	if(game->enemy.data)
		mlx_destroy_image(game->mlx, game->enemy.data);
	free_map(game->map);
	mlx_clear_window(game->mlx, game->window.ptr);
	mlx_destroy_window(game->mlx, game->window.ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	 
}

static void	check_images(t_game *game)
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
		if(game->player.data)
			mlx_destroy_image(game->mlx, game->player.data);
		if(game->wall.data)
			mlx_destroy_image(game->mlx, game->wall.data);
		if(game->floor.data)
			mlx_destroy_image(game->mlx, game->floor.data);
		if(game->collect.data)
			mlx_destroy_image(game->mlx, game->collect.data);
		if(game->exit.data)
			mlx_destroy_image(game->mlx, game->exit.data);
		if(game->enemy.data)
			mlx_destroy_image(game->mlx, game->enemy.data);
		end_game(game);
	}
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
	game->enemy.data = mlx_xpm_file_to_image \
		(game->mlx, "assets/enemy.xpm", &size, &size);
	check_images(game);
}

static void	count_collectibles(t_game *game)
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

static int	check_map_dimensions(t_game *game, char *map_file)
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

static int	load_game_map(t_game *game, char *map_file)
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

static int	init_game(t_game *game, char *map_file)
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

static int	init_window_and_images(t_game *game)
{
    game->window.ptr = mlx_new_window(game->mlx, game->width * TILE_SIZE,
        game->height * TILE_SIZE, "so_long");
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

int start_game(t_game *game, char *map_file)
{
    t_check *map = ft_calloc(1, sizeof(t_check));
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
    if (!validate_map(game->map, game->width, game->height))
    {
        free_map(game->map);
        write(2, "Error\nInvalid map.\n", 20);
        if (game->mlx)
        {
            mlx_destroy_display(game->mlx);
            free(game->mlx);
        }
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
        free_map(game->map);
        if (game->mlx)
        {
            mlx_destroy_display(game->mlx);
            free(game->mlx);
        }
        return (1);
    }
    free_check_map(map);
    return (0);
}

int	main(int argc, char **argv)
{
    t_game	game;

	game.fps = 0;

    if (argc != 2)
    {
        write(2, "Usage: ./so_long <map_file.ber>\n", 33);
        return (1);
    }
	if (!has_ber_extension(argv[1]))
	{
		write(2, "Error : map file must be a .ber\n", 31);
		return (1);
	}
    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);
    if (start_game(&game, argv[1]))
        return (1);
    mlx_key_hook(game.window.ptr, handle_input, &game);
    mlx_hook(game.window.ptr, 17, 0, (int (*)(void *))close_game, &game);
    mlx_loop_hook(game.mlx, render_frame, &game);
    mlx_loop(game.mlx);
	end_game(&game);
    return (0);
}
