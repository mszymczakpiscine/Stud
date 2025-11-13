/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_draw_rect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:49:17 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/28 13:49:17 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

void	rlx_draw_rect(t_window *window, t_rect rect, t_color color)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < rect.size.y)
	{
		x = 0;
		while (x < rect.size.x)
		{
			rlx_draw_pixel_xy(window, rect.origin.x + x, rect.origin.y + y,
				color);
			x++;
		}
		y++;
	}
}
