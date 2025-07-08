/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec3_rotate_by_quat.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 01:14:10 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 01:14:10 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec3	rlx_vec3_rotate_by_quat(t_vec3 u, t_quat q)
{
	return ((t_vec3){
		.x = u.x * (q.x * q.x + q.w * q.w - q.y * q.y - q.z * q.z) + u.y * (2
			* q.x * q.y - 2 * q.w * q.z) + u.z * (2 * q.x * q.z + 2 * q.w
			* q.y),
		.y = u.x * (2 * q.w * q.z + 2 * q.x * q.y) + u.y * (q.w * q.w - q.x
			* q.x + q.y * q.y - q.z * q.z) + u.z * (-2 * q.w * q.x + 2 * q.y
			* q.z),
		.z = u.x * (-2 * q.w * q.y + 2 * q.x * q.z) + u.y * (2 * q.w * q.x + 2
			* q.y * q.z) + u.z * (q.w * q.w - q.x * q.x - q.y * q.y + q.z
			* q.z),
	});
}
