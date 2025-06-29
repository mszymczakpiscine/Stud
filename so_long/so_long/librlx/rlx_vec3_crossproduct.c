/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec3_crossproduct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:16:25 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:51 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec3	rlx_vec3_crossproduct(t_vec3 u, t_vec3 v)
{
	return ((t_vec3){
		.x = u.y * v.z - u.z * v.y,
		.y = u.z * v.x - u.x * v.z,
		.z = u.x * v.y - u.y * v.x,
	});
}
