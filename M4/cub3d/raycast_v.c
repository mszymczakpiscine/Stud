/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:30:37 by aheisch           #+#    #+#             */
/*   Updated: 2025/11/07 15:51:21 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static t_err	cast_ray_loop(t_game *game, t_ray ray, t_vec2 *pos,
		t_ray_hit *out)
{
	t_position	tile_pos;
	t_tile		tile;
	t_direction	face_direction;

	if (sinf(ray.angle) > 0.)
		face_direction = NORTH;
	else
		face_direction = SOUTH;
	if (pos->x < 0. || pos->x >= game->width || pos->y < 0.
		|| pos->y >= game->height)
		return (ERR_BREAK);
	tile_pos = get_tile_pos(pos->x, pos->y, face_direction);
	tile = game->map[tile_pos.y * game->width + tile_pos.x];
	if (tile == TILE_WALL)
	{
		*out = (t_ray_hit){
			.location = (t_vec2){pos->x, pos->y},
			.distance = rlx_vec2_distance(ray.origin, (t_vec2){pos->x, pos->y}),
			.face_direction = face_direction,
			.face_hit_pos = pos->x - floor(pos->x),
		};
		return (ERR_OK);
	}
	return (ERR_FAILED);
}

bool	cast_ray_v(t_ray ray, t_game *game, t_ray_hit *out)
{
	t_vec2	pos;
	size_t	i;
	float	mul;
	t_err	err;

	pos.x = ray.origin.x;
	pos.y = ray.origin.y;
	if (sinf(ray.angle) >= 0.)
		mul = ceilf(pos.y) - pos.y;
	else
		mul = pos.y - floorf(pos.y);
	i = 0;
	while (i < RAY_MAX_STEPS)
	{
		pos.y += mul * signum(sinf(ray.angle));
		pos.x += mul / tanf(ray.angle) * signum(sinf(ray.angle));
		err = cast_ray_loop(game, ray, &pos, out);
		if (err == ERR_BREAK)
			break ;
		if (err == ERR_OK)
			return (true);
		mul = 1.0f;
		i++;
	}
	return (false);
}
