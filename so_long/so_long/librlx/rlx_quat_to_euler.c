/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_quat_to_euler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:45:12 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 18:45:12 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec3	rlx_quat_to_euler(t_quat q)
{
	return ((t_vec3){
		.x = atan2f(2.0f * (q.w * q.x + q.y * q.z), 1.0f - 2.0f * (q.x * q.x
				+ q.y * q.y)),
		.y = 2 * atan2(sqrt(1 + 2 * (q.w * q.y - q.x * q.z)), sqrt(1 - 2 * (q.w
					* q.y - q.x * q.z))) - M_PI / 2,
		.z = atan2f(2.0f * (q.w * q.z + q.x * q.y), 1.0f - 2.0f * (q.y * q.y
				+ q.z * q.z)),
	});
}
