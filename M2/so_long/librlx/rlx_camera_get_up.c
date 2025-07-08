/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_camera_get_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:34:40 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 00:34:40 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec3	rlx_camera_get_up(t_camera *camera)
{
	return (rlx_vec3_normalize(rlx_vec3_rotate_by_quat(camera->up,
				camera->rotation)));
}
