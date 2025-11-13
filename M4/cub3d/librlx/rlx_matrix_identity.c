/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_matrix_identity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:17:30 by aheisch           #+#    #+#             */
/*   Updated: 2025/06/23 15:27:46 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_matrix	rlx_matrix_identity(void)
{
	t_matrix	matrix;

	matrix.m0 = 1.0f;
	matrix.m1 = 0.0f;
	matrix.m2 = 0.0f;
	matrix.m3 = 0.0f;
	matrix.m4 = 0.0f;
	matrix.m5 = 1.0f;
	matrix.m6 = 0.0f;
	matrix.m7 = 0.0f;
	matrix.m8 = 0.0f;
	matrix.m9 = 0.0f;
	matrix.m10 = 1.0f;
	matrix.m11 = 0.0f;
	matrix.m12 = 0.0f;
	matrix.m13 = 0.0f;
	matrix.m14 = 0.0f;
	matrix.m15 = 1.0f;
	return (matrix);
}
