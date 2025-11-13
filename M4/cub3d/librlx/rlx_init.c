/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:58:24 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/30 12:58:24 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"
#include "mlx.h"

t_rlx	rlx_init(void)
{
	t_rlx	rlx;

	rlx.is_ready = false;
	rlx.window.is_ready = false;
	rlx.window.img.z_buffer = NULL;
	rlx.mlx = mlx_init();
	if (!rlx.mlx)
		return (rlx);
	rlx.is_ready = true;
	return (rlx);
}
