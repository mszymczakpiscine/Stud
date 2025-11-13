/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:27:16 by aheisch           #+#    #+#             */
/*   Updated: 2025/11/07 15:27:16 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdlib.h>

t_position	get_tile_pos(float x, float y, t_direction face_direction)
{
	if (face_direction == NORTH)
		return ((t_position){
			.x = (size_t)floor(x),
			.y = (size_t)round(y),
		});
	if (face_direction == SOUTH)
		return ((t_position){
			.x = (size_t)floor(x),
			.y = (size_t)round(y - 1),
		});
	if (face_direction == EAST)
		return ((t_position){
			.x = (size_t)round(x - 1),
			.y = (size_t)floor(y),
		});
	if (face_direction == WEST)
		return ((t_position){
			.x = (size_t)round(x),
			.y = (size_t)floor(y),
		});
	exit(ERR_FAILED);
}

int	signum(float val)
{
	if (val >= 0)
		return (1.);
	else
		return (-1.);
}

t_img	*direction_to_img(t_game *game, t_direction direction)
{
	if (direction == NORTH)
		return (&game->texture_north);
	else if (direction == SOUTH)
		return (&game->texture_south);
	else if (direction == EAST)
		return (&game->texture_east);
	else if (direction == WEST)
		return (&game->texture_west);
	return (NULL);
}

t_color	get_color(t_img *img, size_t x, size_t y)
{
	char	*dst;

	dst = img->addr + (y * img->width + x * (img->bits_per_pixel / 8));
	return (rlx_color_rgb(dst[2], dst[1], dst[0]));
}
