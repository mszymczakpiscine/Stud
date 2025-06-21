/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:42:34 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/21 14:47:20 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	clse_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

void	start_game(t_game *game)
{
	mlx_hook(game->win, 2, 1L<<0, handle_key, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
