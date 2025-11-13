/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_quat_from_axis_angle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:52:17 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 00:52:17 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"
#include <math.h>

t_quat	rlx_quat_from_axis_angle(t_vec3 axis, float angle)
{
	t_quat	result;
	float	angle_sin;

	result = rlx_quat_identity();
	if (rlx_vec3_length(axis) != 0.0f)
	{
		angle /= 2.0f;
		axis = rlx_vec3_normalize(axis);
		angle_sin = sinf(angle);
		result.x = axis.x * angle_sin;
		result.y = axis.y * angle_sin;
		result.z = axis.z * angle_sin;
		result.w = cosf(angle);
		result = rlx_quat_normalize(result);
	}
	return (result);
}
