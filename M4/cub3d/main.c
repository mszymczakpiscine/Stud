/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:41:59 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/21 14:41:59 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "rlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

static void	free_game(t_game *game)
{
	if (!game)
		return ;
	free(game->map);
	if (game->texture_north.data)
		rlx_destroy_image(&game->rlx, &game->texture_north);
	if (game->texture_south.data)
		rlx_destroy_image(&game->rlx, &game->texture_south);
	if (game->texture_east.data)
		rlx_destroy_image(&game->rlx, &game->texture_east);
	if (game->texture_west.data)
		rlx_destroy_image(&game->rlx, &game->texture_west);
	if (game->rlx.window.is_ready)
		rlx_window_close(&game->rlx);
	rlx_close(&game->rlx);
}

static t_err	check_valid_file(char *map_file)
{
	int	fd;

	if (!has_cub_extension(map_file))
		return (ft_putstr_fd("Error\nMap file must be a .cub\n", STDERR_FILENO),
			ERR_FAILED);
	fd = open(map_file, O_RDONLY);
	if (fd >= 0)
		close(fd);
	else
		return (ft_putstr_fd("Error\nCould not open map file\n", STDERR_FILENO),
			ERR_FAILED);
	fd = open(map_file, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
		return (close(fd),
			ft_putstr_fd("Error\nMap path points to a directory\n",
				STDERR_FILENO), ERR_FAILED);
	return (ERR_OK);
}

static int	loop(t_game *game)
{
	rlx_frame_begin(&game->rlx);
	handle_input(game);
	rlx_draw_begin(&game->rlx);
	render_environment(game);
	rlx_draw_end(&game->rlx);
	rlx_frame_end(&game->rlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	game.player.fov = M_PI / 3.;
	if (argc != 2)
		return (ft_putstr_fd("Error\nUsage: ./cub3d <map_file.cub>\n",
				STDERR_FILENO), ERR_FAILED);
	if (check_valid_file(argv[1]))
		return (ERR_FAILED);
	game.rlx = rlx_init();
	if (!game.rlx.is_ready)
		return (ERR_FAILED);
	if (init(&game, argv[1]))
		return (free_game(&game), ERR_FAILED);
	gettimeofday(&game.last_frame, NULL);
	rlx_window_init(&game.rlx, 1280, 720, "cub3d");
	if (!game.rlx.window.is_ready)
		return (free_game(&game), ERR_SYSTEM);
	rlx_loop(&game.rlx, (int (*)(void *))loop, &game);
	free_game(&game);
	return (0);
}
