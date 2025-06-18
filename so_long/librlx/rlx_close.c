/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:58:40 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/30 12:58:40 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"
#include "mlx.h"
#include <stdlib.h>

void	rlx_close(t_rlx *rlx)
{
	if (!rlx || !rlx->mlx)
		return ;
	mlx_destroy_display(rlx->mlx);
	mlx_loop_end(rlx->mlx);
	free(rlx->mlx);
	rlx->mlx = NULL;
}
