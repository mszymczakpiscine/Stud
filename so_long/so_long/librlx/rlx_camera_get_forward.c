/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_camera_get_forward.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:31:10 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/01 00:31:10 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_vec3	rlx_camera_get_forward(t_camera *camera)
{
	return (rlx_vec3_normalize(rlx_vec3_rotate_by_quat(rlx_vec3_forward(),
				camera->rotation)));
}
