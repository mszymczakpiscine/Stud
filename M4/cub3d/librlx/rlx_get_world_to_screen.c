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

#include "rlx.h"

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
	return (rlx_matrix_identity());
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

	if (!camera->_cache_built)
	{
		camera->_view_matrix_cache = get_view_matrix(camera);
		camera->_proj_matrix_cache = get_proj_matrix(camera,
				(float)window->width / (float)window->height);
		camera->_cache_built = true;
	}
	quat = rlx_quat_from_vec3(point);
	quat = rlx_quat_tranform(quat, camera->_view_matrix_cache);
	depth = rlx_vec3_from_quat(quat).z;
	quat = rlx_quat_tranform(quat, camera->_proj_matrix_cache);
	point = rlx_vec3_from_quat(quat);
	point.x = (point.x + 1.0f) / 2.0f * (float)window->width;
	point.y = (point.y + 1.0f) / 2.0f * (float)window->height;
	point.z = depth;
	return (point);
}
