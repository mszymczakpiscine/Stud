/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:25:15 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/28 14:25:30 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/keysym.h>
#include <math.h>
#include <sys/time.h>

static void	movement(t_game *game, float delta)
{
	if (rlx_is_key_down(&game->rlx.window, XK_w))
	{
		game->player.position.y += sin(game->player.angle) * delta;
		game->player.position.x += cos(game->player.angle) * delta;
	}
	if (rlx_is_key_down(&game->rlx.window, XK_s))
	{
		game->player.position.y -= sin(game->player.angle) * delta;
		game->player.position.x -= cos(game->player.angle) * delta;
	}
	if (rlx_is_key_down(&game->rlx.window, XK_a))
	{
		game->player.position.x += sin(game->player.angle) * delta;
		game->player.position.y -= cos(game->player.angle) * delta;
	}
	if (rlx_is_key_down(&game->rlx.window, XK_d))
	{
		game->player.position.x -= sin(game->player.angle) * delta;
		game->player.position.y += cos(game->player.angle) * delta;
	}
}

void	handle_input(t_game *game)
{
	struct timeval	now;
	float			delta;

	gettimeofday(&now, NULL);
	delta = now.tv_sec - game->last_frame.tv_sec + (now.tv_usec
			- game->last_frame.tv_usec) / 1000000.;
	game->last_frame = now;
	delta *= 1.5;
	if (rlx_is_key_down(&game->rlx.window, XK_Escape))
		rlx_loop_end(&game->rlx);
	movement(game, delta);
	if (rlx_is_key_down(&game->rlx.window, XK_Left))
		game->player.angle -= delta;
	if (rlx_is_key_down(&game->rlx.window, XK_Right))
		game->player.angle += delta;
}
