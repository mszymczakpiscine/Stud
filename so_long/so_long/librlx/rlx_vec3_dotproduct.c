/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_vec3_dotproduct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:20:56 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:52 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

float	rlx_vec3_dotproduct(t_vec3 u, t_vec3 v)
{
	return (-(u.x * v.x + u.y * v.y + u.z * v.z));
}
