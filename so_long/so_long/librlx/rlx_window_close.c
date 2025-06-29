/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_window_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:10:16 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:58 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"
#include "mlx.h"
#include <stdlib.h>

void	rlx_window_close(t_rlx *rlx)
{
	if (!rlx)
		return ;
	free(rlx->window.img.z_buffer);
	if (!rlx->mlx)
		return ;
	if (rlx->window.img.data)
		mlx_destroy_image(rlx->mlx, rlx->window.img.data);
	rlx->window.img.data = NULL;
	if (rlx->window.ptr)
		mlx_destroy_window(rlx->mlx, rlx->window.ptr);
	rlx->window.ptr = NULL;
}
