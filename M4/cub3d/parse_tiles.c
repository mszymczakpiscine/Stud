/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rustparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:10:47 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/31 15:10:47 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static t_err	parse_tile(t_game *game, size_t idx, char c,
		bool *player_pos_is_set)
{
	if (idx >= (size_t)game->width * (size_t)game->height)
		return (ERR_BREAK);
	game->map[idx] = char_to_tile(c);
	if (game->map[idx] == TILE_INVALID)
		return (free(game->map), game->map = NULL,
			ft_putstr_fd("Error\nInvalid tile character\n", 2), ERR_FAILED);
	if (game->map[idx] >= TILE_EAST && game->map[idx] <= TILE_NORTH)
	{
		if (*player_pos_is_set)
			return (free(game->map), game->map = NULL,
				ft_putstr_fd("Error\nMultiple starting points\n", 2),
				ERR_FAILED);
		game->player.position.x = idx % game->width + 0.5f;
		game->player.position.y = idx / (float)game->width;
		game->player.angle = (game->map[idx] - TILE_EAST) * M_PI / 2.f;
		*player_pos_is_set = true;
	}
	return (ERR_OK);
}

static t_err	parse_row(t_game *game, char *line, size_t *idx,
		bool *player_pos_is_set)
{
	size_t	line_idx;
	t_err	err;

	if (!line)
		return (ERR_BREAK);
	if (line[0] == '\n' && *idx >= (size_t)game->width * (size_t)game->height)
		return (ERR_BREAK);
	if (line[0] == '\n')
		return (free(game->map), game->map = NULL,
			ft_putstr_fd("Error\nEmpty line in map\n", 2), ERR_FAILED);
	line_idx = 0;
	while (line[line_idx] && line[line_idx] != '\n')
	{
		err = parse_tile(game, *idx, line[line_idx++], player_pos_is_set);
		if (err == ERR_BREAK)
			break ;
		if (err == ERR_FAILED)
			return (ERR_FAILED);
		(*idx)++;
	}
	while (line_idx++ < (size_t)game->width && *idx < (size_t)game->width
		* (size_t)game->height)
		game->map[(*idx)++] = TILE_SPACE;
	return (ERR_OK);
}

t_err	parse_tiles(t_game *game, t_lines *lines)
{
	size_t	idx;
	bool	player_pos_is_set;
	t_err	err;
	char	*line;

	player_pos_is_set = false;
	skip_metadata(lines);
	game->map = malloc(sizeof(t_tile) * game->width * game->height);
	if (game->map == NULL)
		return (ERR_SYSTEM);
	idx = 0;
	while (true)
	{
		line = lines_next(lines);
		err = parse_row(game, line, &idx, &player_pos_is_set);
		if (err == ERR_BREAK)
			break ;
		if (err == ERR_FAILED)
			return (ERR_FAILED);
	}
	if (!player_pos_is_set)
		return (free(game->map), game->map = NULL,
			ft_putstr_fd("Error\nNo starting point\n", 2), ERR_FAILED);
	return (ERR_OK);
}

bool	has_cub_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".cub", 5) == 0);
}
