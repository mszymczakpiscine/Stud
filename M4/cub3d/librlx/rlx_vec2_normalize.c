/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec2_normalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:37:14 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/28 16:37:14 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_vec2	rlx_vec2_normalize(t_vec2 u)
{
	float	length;
	float	inv_length;

	length = rlx_vec2_length(u);
	if (length == 0.f)
		return (u);
	inv_length = 1.f / length;
	return ((t_vec2){
		.x = u.x * inv_length,
		.y = u.y * inv_length,
	});
}
