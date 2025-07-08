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

#include "librlx.h"
#include <math.h>

void	rlx_draw_pixel_depth(t_window *window, t_vec2 p, t_color color,
		float depth)
{
	size_t	x;
	size_t	y;

	x = (int)floor(p.x);
	y = (int)floor(p.y);
	if (x < 0 || x >= window->width || y < 0 || y >= window->height)
		return ;
	if (depth >= window->img.z_buffer[x + y * window->width])
		return ;
	window->img.z_buffer[x + y * window->width] = depth;
	rlx_draw_pixel_unchecked(window, x, y, color);
}
