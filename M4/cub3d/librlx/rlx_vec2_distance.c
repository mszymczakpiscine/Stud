/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec2_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:26:34 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/28 13:26:34 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"
#include <math.h>

float	rlx_vec2_distance(t_vec2 a, t_vec2 b)
{
	return (sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2)));
}
