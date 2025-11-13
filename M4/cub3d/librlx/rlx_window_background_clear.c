/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_window_background_clear.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:57:19 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:57 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

void	rlx_window_background_clear(t_window *window, t_color color)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			rlx_draw_pixel_xy(window, x, y, color);
			window->img.z_buffer[y * window->width + x] = RLX_CAMERA_FAR;
			x++;
		}
		y++;
	}
}
