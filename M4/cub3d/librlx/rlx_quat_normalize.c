/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_quat_normalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:47:37 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 00:47:37 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"
#include <math.h>

t_quat	rlx_quat_normalize(t_quat q)
{
	float	length;
	float	inv_length;

	length = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	if (length == 0.f)
		return (q);
	inv_length = 1.f / length;
	return ((t_quat){
		.x = q.x * inv_length,
		.y = q.y * inv_length,
		.z = q.z * inv_length,
		.w = q.w * inv_length,
	});
}
