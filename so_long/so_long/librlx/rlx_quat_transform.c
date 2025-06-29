/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_quat_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:09:37 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:47 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_quat	rlx_quat_tranform(t_quat quat, t_matrix mat)
{
	return ((t_quat){
		.x = mat.m0 * quat.x + mat.m4 * quat.y + mat.m8 * quat.z + mat.m12,
		.y = mat.m1 * quat.x + mat.m5 * quat.y + mat.m9 * quat.z + mat.m13,
		.z = mat.m2 * quat.x + mat.m6 * quat.y + mat.m10 * quat.z + mat.m14,
		.w = mat.m3 * quat.x + mat.m7 * quat.y + mat.m11 * quat.z + mat.m15,
	});
}
