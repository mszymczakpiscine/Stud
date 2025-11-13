/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec3_lerp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:14:41 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/28 15:14:41 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_vec3	rlx_vec3_lerp(t_vec3 from, t_vec3 to, float factor)
{
	return ((t_vec3){
		.x = rlx_lerp(from.x, to.x, factor),
		.y = rlx_lerp(from.y, to.y, factor),
		.z = rlx_lerp(from.z, to.z, factor),
	});
}
