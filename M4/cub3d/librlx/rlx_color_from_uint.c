/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_color_from_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:17:05 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:35 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_color	rlx_color_from_uint(unsigned int color)
{
	return ((t_color){
		.a = color >> 24,
		.r = color >> 16,
		.g = color >> 8,
		.b = color,
	});
}
