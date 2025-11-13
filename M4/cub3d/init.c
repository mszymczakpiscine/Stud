/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:36:48 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/21 15:10:30 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

/// ERR_OK / ERR_FAILED
static t_err	check_map_dimensions(t_game *game, char *map_file)
{
	if (get_dimensions(map_file, &game->width, &game->height))
		return (ERR_FAILED);
	if (game->height < 3 || game->width < 3)
		return (ft_putstr_fd("Error\nInvalid map dimensions.\n", STDERR_FILENO),
			ERR_FAILED);
	return (0);
}

/// ERR_OK / ERR_FAILED
static t_err	load_tiles(t_game *game, t_lines *lines)
{
	t_err	err;

	err = parse_tiles(game, lines);
	if (err == ERR_SYSTEM)
		return (ft_putstr_fd("Error\nAllocation failed\n", STDERR_FILENO), err);
	if (err == ERR_FAILED)
		return (err);
	if (!flood_fill(game))
		return (ft_putstr_fd("Error\nMap is not closed\n", STDERR_FILENO),
			ERR_FAILED);
	return (ERR_OK);
}

t_err	init(t_game *game, char *map_file)
{
	int		fd;
	t_lines	lines;
	t_err	err;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (ERR_SYSTEM);
	lines = lines_new(fd);
	err = parse_metadata(game, &lines);
	if (err)
		return (lines_destroy(&lines), err);
	if (check_map_dimensions(game, map_file))
		return (lines_destroy(&lines), ERR_FAILED);
	if (load_tiles(game, &lines))
		return (lines_destroy(&lines), ERR_FAILED);
	return (lines_destroy(&lines), ERR_OK);
}
