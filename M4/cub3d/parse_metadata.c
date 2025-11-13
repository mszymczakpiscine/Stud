/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:09:15 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/31 16:09:15 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

static t_err	parse_metadata_one(t_game *game, t_metadata *data, char *s)
{
	if (ft_strncmp(s, data->id, ft_strlen(data->id)) != 0)
		return (ERR_CONTINUE);
	if (data->is_set)
		return (ft_putstr_fd("Error\nDuplicate in metadata\n", 2), ERR_FAILED);
	if (data->is_color)
	{
		if (parse_color(data->out.color, s + ft_strlen(data->id) + 1))
			return (ft_putstr_fd("Error\nInvalid metadata\n", 2), ERR_FAILED);
	}
	else
	{
		if (parse_image(&game->rlx, data->out.img, s + ft_strlen(data->id) + 1))
			return (ft_putstr_fd("Error\nInvalid metadata\n", 2), ERR_FAILED);
	}
	data->is_set = true;
	return (ERR_OK);
}

static t_err	parse_metadata_loop(t_game *game,
		t_lines *lines, t_metadata data[6])
{
	t_err	err;
	char	*line;
	size_t	i;
	bool	is_metadata;

	line = lines_peek(lines);
	if (!line)
		return (ft_putstr_fd("Error\nEmpty map\n", 2), ERR_FAILED);
	is_metadata = false;
	i = 0;
	while (i < 6)
	{
		err = parse_metadata_one(game, &data[i++], line);
		if (err == ERR_FAILED)
			return (err);
		if (err == ERR_CONTINUE)
			continue ;
		is_metadata = true;
	}
	if (!is_metadata && line[0] != '\n')
		return (ERR_BREAK);
	lines_next(lines);
	return (ERR_OK);
}

t_err	parse_metadata(t_game *game, t_lines *lines)
{
	t_metadata	data[6];
	t_err		err;

	data[0] = (t_metadata){false, "NO", false, {&game->texture_north}};
	data[1] = (t_metadata){false, "SO", false, {&game->texture_south}};
	data[2] = (t_metadata){false, "WE", false, {&game->texture_west}};
	data[3] = (t_metadata){false, "EA", false, {&game->texture_east}};
	data[4] = (t_metadata){false, "F", true, {.color = &game->color_floor}};
	data[5] = (t_metadata){false, "C", true, {.color = &game->color_ceiling}};
	while (true)
	{
		err = parse_metadata_loop(game, lines, data);
		if (err == ERR_FAILED)
			return (ERR_FAILED);
		if (err == ERR_BREAK)
			break ;
	}
	if (!(data[0].is_set && data[1].is_set && data[2].is_set && data[3].is_set
			&& data[3].is_set && data[4].is_set && data[5].is_set))
		return (ft_putstr_fd("Error\nMissing information\n", 2), ERR_FAILED);
	return (ERR_OK);
}
