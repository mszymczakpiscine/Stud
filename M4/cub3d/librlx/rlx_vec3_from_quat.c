/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec3_from_quat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:07:02 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:53 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_vec3	rlx_vec3_from_quat(t_quat quat)
{
	return ((t_vec3){
		.x = quat.x / quat.w,
		.y = quat.y / quat.w,
		.z = quat.z / quat.w,
	});
}
