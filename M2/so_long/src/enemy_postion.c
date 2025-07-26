/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_postion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:46:18 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:00:15 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	init_enemy_position(t_game *game)
{
	int	i;
	int	map_size;

	if (!game->map)
	{
		write(2, "Error: map not loaded\n", 22);
		exit(EXIT_FAILURE);
	}
	map_size = game->width * game->height;
	i = 0;
	while (i < map_size)
	{
		if (game->map[i] == TILE_ENEMY)
		{
			game->enemy_x = i % game->width;
			game->enemy_y = i / game->width;
			printf("Enemy found at (%d, %d)\n", game->enemy_x, game->enemy_y);
			return ;
		}
		i++;
	}
	game->enemy_x = -1;
	game->enemy_y = -1;
	printf("Enemy not found in map, default position used\n");
}

static void	get_next_pos(t_game *g, int *x, int *y)
{
	int	dx;
	int	dy;

	dx = g->player_x - g->enemy_x;
	dy = g->player_y - g->enemy_y;
	*x = g->enemy_x;
	*y = g->enemy_y;
	if (ft_abs(dx) > ft_abs(dy))
	{
		if (dx > 0)
			(*x)++;
		else if (dx < 0)
			(*x)--;
	}
	else
	{
		if (dy > 0)
			(*y)++;
		else if (dy < 0)
			(*y)--;
	}
}

static int	is_valid_move(t_game *g, int x, int y)
{
	return (x >= 0 && x < g->width
		&& y >= 0 && y < g->height
		&& g->map[y * g->width + x] != TILE_WALL);
}

void	move_enemy_towards_player(t_game *g)
{
	int	next_x;
	int	next_y;

	if (g->enemy_x == -1 || g->enemy_y == -1)
		return ;
	get_next_pos(g, &next_x, &next_y);
	if (is_valid_move(g, next_x, next_y))
	{
		g->enemy_x = next_x;
		g->enemy_y = next_y;
		g->needs_redraw = 1;
	}
}
