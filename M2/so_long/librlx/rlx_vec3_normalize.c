/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec3_normalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:21:08 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:55 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"
#include <math.h>

t_vec3	rlx_vec3_normalize(t_vec3 u)
{
	float	length;
	float	inv_length;

	length = sqrtf(u.x * u.x + u.y * u.y + u.z * u.z);
	if (length == 0.f)
		return (u);
	inv_length = 1.f / length;
	return ((t_vec3){
		.x = u.x * inv_length,
		.y = u.y * inv_length,
		.z = u.z * inv_length,
	});
}
