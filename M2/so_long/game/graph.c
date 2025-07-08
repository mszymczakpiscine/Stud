/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:01:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/21 15:21:36 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_windows(game->mlx, game->width * 64, game->height * 64, "so_long");
}

void	load_textures(t_game *game)
{
	int	size = 64;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &size, &size);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &size, &size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &size, &size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.tpm", &size, &size);
	game->collect_img =mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &size, &size);
}

void	render_map(t_game *game)
{
	int y;
	int x;

	y  = 0;
	x  = 0;
	while (y < game->height)
	{
		while (x < game->width)
		{
			void *img = NULL;
			t_tile tile = game->map[y * game->width + x];
			if (tile == TILE_WALL)
				img = game->wall_img;
			else if (tile == TILE_FLOOR)
                img = game->floor_img;
			else if (tile == TILE_START)
				img = game->player_img;
			else if (tile == TILE_ITEM)
				img = game->collect_img;
			else if (tile == TILE_EXIT)
				img = game->exit_img;
			mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
			x++;
		}
		y++;
	}	
}

void try_move(t_game *game, int dx, int dy) 
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;

    if (new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
        return;
    t_tile *target = &game->map[new_y * game->width + new_x];
    if (*target == TILE_WALL)
        return;
    if (*target == TILE_ITEM) 
	{
        game->collected++;
        *target = TILE_EMPTY;
	}
    if (*target == TILE_EXIT) 
	{
        if (game->collected == game->collectibles) 
		{
            render_victory_screen(game);
			game->is_finished = 1;
			return ;
        }
		else 
		{
            // Si le joueur n'a pas encore tous les collectibles, ne pas autoriser la sortie
            return;
        }
    }
    game->player_x = new_x;
    game->player_y = new_y;
    render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (game->is_finished)
        return 0;
    if (keycode == 65362)        // Flèche haut
        try_move(game, 0, -1);
    else if (keycode == 65364)   // Flèche bas
        try_move(game, 0, 1);
    else if (keycode == 65361)   // Flèche gauche
        try_move(game, -1, 0);
    else if (keycode == 65363)   // Flèche droite
        try_move(game, 1, 0);
    return 0;
}


