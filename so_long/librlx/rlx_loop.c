/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:34:09 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/30 12:54:57 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"
#include "mlx.h"

void	rlx_loop(t_rlx *rlx, int loop(void *), void *state)
{
	mlx_loop_hook(rlx->mlx, loop, state);
	mlx_loop(rlx->mlx);
}
