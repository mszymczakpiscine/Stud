/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec2_lerp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:14:41 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/28 15:14:41 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec2	rlx_vec2_lerp(t_vec2 from, t_vec2 to, float factor)
{
	return ((t_vec2){
		.x = rlx_lerp(from.x, to.x, factor),
		.y = rlx_lerp(from.y, to.y, factor),
	});
}
