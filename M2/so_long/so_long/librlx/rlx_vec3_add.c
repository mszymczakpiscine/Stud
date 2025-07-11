/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec3_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 00:02:41 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:50 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec3	rlx_vec3_add(t_vec3 u, t_vec3 v)
{
	return ((t_vec3){
		.x = u.x + v.x,
		.y = u.y + v.y,
		.z = u.z + v.z,
	});
}
