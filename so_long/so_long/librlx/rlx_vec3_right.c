/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec3_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 01:25:57 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 01:30:53 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec3	rlx_vec3_right(void)
{
	return ((t_vec3){
		.x = 1.0f,
		.y = 0.0f,
		.z = 0.0f,
	});
}
