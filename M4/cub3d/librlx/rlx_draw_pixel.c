/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_draw_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:03:40 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/12 12:41:22 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"
#include <math.h>

void	rlx_draw_pixel(t_window *window, t_vec2 p, t_color color)
{
	if (p.x < 0 || p.x >= window->width || p.y < 0 || p.y >= window->height)
		return ;
	rlx_draw_pixel_unchecked(window, floor(p.x), floor(p.y), color);
}
