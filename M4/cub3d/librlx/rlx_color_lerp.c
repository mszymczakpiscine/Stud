/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_color_lerp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:10:59 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/28 15:10:59 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_color	rlx_color_lerp(t_color from, t_color to, float factor)
{
	return ((t_color){
		.a = rlx_lerp(from.a, to.a, factor),
		.r = rlx_lerp(from.r, to.r, factor),
		.g = rlx_lerp(from.g, to.g, factor),
		.b = rlx_lerp(from.b, to.b, factor),
	});
}
