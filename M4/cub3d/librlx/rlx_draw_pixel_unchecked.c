/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_draw_pixel_unchecked.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:03:40 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/12 14:03:26 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

void	rlx_draw_pixel_unchecked(t_window *window, size_t x, size_t y,
		t_color color)
{
	char	*dst;

	dst = window->img.addr + (y * window->img.width + x
			* (window->img.bits_per_pixel / 8));
	*(unsigned int *)dst = rlx_color_to_uint(color);
}
