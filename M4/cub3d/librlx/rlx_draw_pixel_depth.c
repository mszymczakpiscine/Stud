/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_draw_pixel_depth.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:03:40 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/12 12:41:40 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"
#include <math.h>

void	rlx_draw_pixel_depth(t_window *window, t_vec2 p, t_color color,
		float depth)
{
	const size_t	x = floor(p.x);
	const size_t	y = floor(p.y);

	if (p.x < 0 || p.x >= window->width || p.y < 0 || p.y >= window->height)
		return ;
	if (depth >= window->img.z_buffer[x + y * window->width])
		return ;
	window->img.z_buffer[x + y * window->width] = depth;
	rlx_draw_pixel_unchecked(window, x, y, color);
}
