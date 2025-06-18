/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_get_world_to_screen.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:06:14 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 17:06:14 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

static t_matrix	get_proj_matrix(t_camera *camera, float aspect)
{
	float	top;
	float	right;

	if (camera->projection == RLX_CAMERA_ISOMETRIC)
	{
		top = camera->fov / 2.0f;
		right = top * aspect;
		return (rlx_matrix_ortho(right, top, RLX_CAMERA_NEAR, RLX_CAMERA_FAR));
	}
	else if (camera->projection == RLX_CAMERA_PERSPECTIVE)
	{
		return (rlx_matrix_perspective(camera->fov * RLX_DEG2RAD, aspect,
				RLX_CAMERA_NEAR, RLX_CAMERA_FAR));
	}
	return ((t_matrix){});
}

// TODO !!!!! camera's forward vector should be inverted !
static t_matrix	get_view_matrix(t_camera *camera)
{
	return (rlx_matrix_lookat(camera->position, rlx_vec3_sub(camera->position,
				rlx_camera_get_forward(camera)), rlx_camera_get_up(camera)));
}

t_vec3	rlx_get_world_to_screen(t_window *window, t_camera *camera,
		t_vec3 point)
{
	t_quat	quat;
	float	depth;

	quat = rlx_quat_from_vec3(point);
	quat = rlx_quat_tranform(quat, get_view_matrix(camera));
	depth = rlx_vec3_from_quat(quat).z;
	quat = rlx_quat_tranform(quat, get_proj_matrix(camera, (float)window->width
				/ (float)window->height));
	point = rlx_vec3_from_quat(quat);
	point.x = (point.x + 1.0f) / 2.0f * (float)window->width;
	point.y = (point.y + 1.0f) / 2.0f * (float)window->height;
	point.z = depth;
	return (point);
}
