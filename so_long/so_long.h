/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:12 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/17 14:34:04 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>

typedef enum	e_tile
{
	TILE_EMPTY = 0, 
	TILE_WALL,
	TILE_FLOOR,
	TILE_ITEM,
	TILE_EXIT,
	TILE_START,
	//TILE_MOB,
	TILE_INVALID,
}	t_tile;

typedef struct s_game 
{
    void    *mlx;
    void    *win;
    t_tile  *map;
    int     width;
    int     height;
	void    *wall_img;
    void    *player_img;
    void    *exit_img;
    void    *collect_img;
	void	*floor_img;
	int 	player_x;
    int 	player_y;
	int 	collectibles;
    int 	collected;
	int     is_finished;

} t_game;


t_tile	char_to_tile(char c);









#endif
