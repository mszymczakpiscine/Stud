/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_matrix_ortho.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:14:33 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 17:14:33 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_matrix	rlx_matrix_ortho(float right, float top, float near, float far)
{
	t_matrix	matrix;
	float		rl;
	float		tb;
	float		fn;

	rl = 2 * right;
	tb = 2 * top;
	fn = far - near;
	matrix.m0 = 2.0f / rl;
	matrix.m1 = 0.0f;
	matrix.m2 = 0.0f;
	matrix.m3 = 0.0f;
	matrix.m4 = 0.0f;
	matrix.m5 = -2.0f / tb;
	matrix.m6 = 0.0f;
	matrix.m7 = 0.0f;
	matrix.m8 = 0.0f;
	matrix.m9 = 0.0f;
	matrix.m10 = -2.0f / fn;
	matrix.m11 = 0.0f;
	matrix.m12 = 0.0f;
	matrix.m13 = 0.0f;
	matrix.m14 = (far + near) / fn;
	matrix.m15 = 1.0f;
	return (matrix);
}
