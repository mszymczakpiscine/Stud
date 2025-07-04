/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_quat_identity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:31:52 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/31 19:31:52 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

t_quat	rlx_quat_identity(void)
{
	return ((t_quat){
		.x = 0.0f,
		.y = 0.0f,
		.z = 0.0f,
		.w = 1.0f,
	});
}
