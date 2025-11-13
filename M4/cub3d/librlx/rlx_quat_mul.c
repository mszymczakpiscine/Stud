/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_quat_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 01:18:52 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 01:18:52 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_quat	rlx_quat_mul(t_quat q, t_quat p)
{
	return ((t_quat){
		.x = q.x * p.w + q.w * p.x + q.y * p.z - q.z * p.y,
		.y = q.y * p.w + q.w * p.y + q.z * p.x - q.x * p.z,
		.z = q.z * p.w + q.w * p.z + q.x * p.y - q.y * p.x,
		.w = q.w * p.w - q.x * p.x - q.y * p.y - q.z * p.z,
	});
}
