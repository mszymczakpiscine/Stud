/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_is_key_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:21:05 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/30 13:21:05 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"

bool	rlx_is_key_down(t_window *window, int keycode)
{
	size_t	i;

	i = 0;
	while (i < window->input.n_keys)
	{
		if (window->input.keys[i] == keycode)
			return (true);
		i++;
	}
	return (false);
}
