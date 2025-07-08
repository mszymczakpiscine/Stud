/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_draw_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:21:40 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:42 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"
#include "mlx.h"

void	rlx_draw_end(t_rlx *rlx)
{
	mlx_put_image_to_window(rlx->mlx, rlx->window.ptr, rlx->window.img.data, 0,
		0);
}
