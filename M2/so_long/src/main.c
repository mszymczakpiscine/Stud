/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:40:21 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:14:26 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

void	end_game(t_game *game)
{
	mlx_loop_end(game->mlx);
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
	free_map(game->map);
	mlx_clear_window(game->mlx, game->window.ptr);
	mlx_destroy_window(game->mlx, game->window.ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
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
