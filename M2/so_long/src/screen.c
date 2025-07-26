/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:44:58 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:45:33 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_steps_to_screen(t_game *game)
{
	char	*steps_str;
	char	*display;

	steps_str = ft_itoa(game->steps);
	if (!steps_str)
		return ;
	display = ft_strjoin("Steps: ", steps_str);
	free(steps_str);
	if (!display)
		return ;
	mlx_string_put(game->mlx, game->window.ptr, 10, 20, 0xFFFFFF, display);
	free(display);
}
