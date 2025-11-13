/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_color_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:27:51 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:37 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_color	rlx_color_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((t_color){
		.a = 0xFF,
		.r = r,
		.g = g,
		.b = b,
	});
}
