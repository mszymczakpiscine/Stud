/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_frame_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:07:08 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/30 15:07:08 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

void	rlx_frame_end(t_rlx *rlx)
{
	size_t	i;

	i = 0;
	while (i < rlx->window.input.n_keys)
	{
		rlx->window.input.prev_keys[i] = rlx->window.input.keys[i];
		i++;
	}
	rlx->window.input.prev_n_keys = rlx->window.input.n_keys;
}
