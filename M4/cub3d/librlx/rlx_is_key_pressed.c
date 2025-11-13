/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_is_key_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:56:45 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/30 14:56:45 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

bool	rlx_is_key_pressed(t_window *window, int keycode)
{
	size_t	i;

	if (!rlx_is_key_down(window, keycode))
		return (false);
	i = 0;
	while (i < window->input.prev_n_keys)
	{
		if (window->input.prev_keys[i] == keycode)
			return (false);
		i++;
	}
	return (true);
}
