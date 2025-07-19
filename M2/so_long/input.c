/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:22:37 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/19 11:41:26 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	move_player(game, keycode);
	return (0);
}

int	handle_close(t_game *game)
{
	(void)game;
	ft_printf("Game exited.\n");
	exit(0);
	return (0);
}
