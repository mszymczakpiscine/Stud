/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:42:05 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/28 12:42:05 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "rlx.h"
#include <math.h>

bool	cast_ray(t_ray ray, t_game *game, t_ray_hit *out)
{
	t_ray_hit	hit_h;
	t_ray_hit	hit_v;
	bool		is_hit_h;
	bool		is_hit_v;

	is_hit_h = cast_ray_h(ray, game, &hit_h);
	if (tanf(ray.angle) != 0.)
		is_hit_v = cast_ray_v(ray, game, &hit_v);
	else
		is_hit_v = false;
	if (is_hit_h && is_hit_v)
	{
		if (hit_h.distance < hit_v.distance)
			*out = hit_h;
		else
			*out = hit_v;
	}
	else if (is_hit_h)
		*out = hit_h;
	else if (is_hit_v)
		*out = hit_v;
	else
		return (false);
	return (true);
}

static void	render_ray_loop(t_game *game, t_ray_hit hit, t_position pos)
{
	t_color	color;
	float	img_y;
	t_img	*img;

	img_y = (pos.y - roundf(game->rlx.window.height / 2.
				- ((game->rlx.window.height / 2.) / hit.distance)))
		/ (roundf(game->rlx.window.height / 2. + ((game->rlx.window.height / 2.)
					/ hit.distance)) - roundf(game->rlx.window.height / 2.
				- ((game->rlx.window.height / 2.) / hit.distance)));
	img = direction_to_img(game, hit.face_direction);
	color = get_color(img, hit.face_hit_pos * img->width, img_y * img->height);
	rlx_draw_pixel_xy(&game->rlx.window, pos.x, pos.y, color);
}

void	render_ray(t_game *game, t_ray_hit hit, t_position pos)
{
	t_vec2	f;
	t_vec2	h;

	f = (t_vec2){cosf(game->player.angle), sinf(game->player.angle)};
	h = rlx_vec2_sub(hit.location, game->player.position);
	hit.distance = rlx_vec2_project(h, f);
	if (hit.distance > 1.)
		pos.y = roundf(game->rlx.window.height / 2. - ((game->rlx.window.height
						/ 2.) / hit.distance));
	else
		pos.y = 0;
	while (pos.y < roundf(game->rlx.window.height / 2.
			+ ((game->rlx.window.height / 2.) / hit.distance)))
	{
		if (pos.x >= game->rlx.window.width || pos.y >= game->rlx.window.height)
			break ;
		render_ray_loop(game, hit, pos);
		pos.y++;
	}
}

void	render_environment(t_game *game)
{
	t_ray_hit	hit;
	t_position	pos;
	t_ray		ray;

	rlx_draw_rect(&game->rlx.window, (t_rect){.origin.x = 0., .origin.y = 0.,
		.size.x = game->rlx.window.width, .size.y = game->rlx.window.height
		/ 2.}, game->color_ceiling);
	rlx_draw_rect(&game->rlx.window, (t_rect){.origin.x = 0.,
		.origin.y = game->rlx.window.height / 2.,
		.size.x = game->rlx.window.width, .size.y = game->rlx.window.height},
		game->color_floor);
	pos.x = 0;
	while (pos.x < game->rlx.window.width)
	{
		ray = (t_ray){
			.origin = game->player.position,
			.angle = game->player.angle + game->player.fov * (pos.x
				- game->rlx.window.width / 2.) / game->rlx.window.width
			/ 2.,
		};
		if (cast_ray(ray, game, &hit))
			render_ray(game, hit, pos);
		pos.x++;
	}
}
