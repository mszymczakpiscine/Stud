/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_draw_pixel_xy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:03:40 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/12 14:03:28 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

void	rlx_draw_pixel_xy(t_window *window, size_t x, size_t y, t_color color)
{
	if (x < 0 || x >= window->width || y < 0 || y >= window->height)
		return ;
	rlx_draw_pixel_unchecked(window, x, y, color);
}
