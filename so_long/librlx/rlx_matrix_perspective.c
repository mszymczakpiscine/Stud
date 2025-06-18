/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_matrix_perspective.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:18:37 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 17:18:37 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"
#include <math.h>

t_matrix	rlx_matrix_perspective(float fovY, float aspect, float near,
		float far)
{
	float	top;
	float	right;
	float	witdh;
	float	height;
	float	depth;

	top = near * tan(fovY * 0.5f);
	right = top * aspect;
	witdh = 2 * right;
	height = 2 * top;
	depth = (far - near);
	return ((t_matrix){
		.m0 = (near * 2.f) / witdh, .m1 = 0.f, .m2 = 0.f, .m3 = 0.f,
		.m4 = 0.f, .m5 = -(near * 2.f) / height, .m6 = 0.f, .m7 = 0.f,
		.m8 = 0.f, .m9 = 0.f, .m10 = -(far + near) / depth, .m11 = -1.f,
		.m12 = 0.f, .m13 = 0.f, .m14 = (far * near * 2.f) / depth, .m15 = 0.f,
	});
}
