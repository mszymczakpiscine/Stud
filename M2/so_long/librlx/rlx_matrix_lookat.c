/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_matrix_lookat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:17:30 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 17:17:30 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_matrix	rlx_matrix_lookat(t_vec3 position, t_vec3 target, t_vec3 up)
{
	t_matrix	matrix;
	t_vec3		vz;
	t_vec3		vx;
	t_vec3		vy;

	vz = rlx_vec3_normalize(rlx_vec3_sub(position, target));
	vx = rlx_vec3_normalize(rlx_vec3_crossproduct(up, vz));
	vy = rlx_vec3_crossproduct(vz, vx);
	matrix.m0 = vx.x;
	matrix.m1 = vy.x;
	matrix.m2 = vz.x;
	matrix.m3 = 0.0f;
	matrix.m4 = vx.y;
	matrix.m5 = vy.y;
	matrix.m6 = vz.y;
	matrix.m7 = 0.0f;
	matrix.m8 = vx.z;
	matrix.m9 = vy.z;
	matrix.m10 = vz.z;
	matrix.m11 = 0.0f;
	matrix.m12 = rlx_vec3_dotproduct(vx, position);
	matrix.m13 = rlx_vec3_dotproduct(vy, position);
	matrix.m14 = rlx_vec3_dotproduct(vz, position);
	matrix.m15 = -1.0f;
	return (matrix);
}
