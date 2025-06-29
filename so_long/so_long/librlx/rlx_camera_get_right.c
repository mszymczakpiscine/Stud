/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_camera_get_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:36:13 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 00:36:13 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec3	rlx_camera_get_right(t_camera *camera)
{
	t_vec3	forward;
	t_vec3	up;

	forward = rlx_camera_get_forward(camera);
	up = rlx_camera_get_up(camera);
	return (rlx_vec3_normalize(rlx_vec3_crossproduct(forward, up)));
}
