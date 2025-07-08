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

# include "../librlx/librlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define TILE_SIZE 64
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_ESC 65307

typedef enum e_tile 
{
    TILE_EMPTY = 0,
    TILE_WALL,
    TILE_FLOOR,
    TILE_ITEM,
    TILE_EXIT,
    TILE_START,
    TILE_INVALID
} t_tile;

typedef struct s_game 
{
    t_rlx       rlx;
    t_window    *win;
    t_tile      *map;
    int         width;
    int         height;
    t_img       wall;
    t_img       player;
    t_img       exit;
    t_img       collect;
    t_img       floor;
    int         player_x;
    int         player_y;
    int         collectibles;
    int         collected;
    int         steps;
    bool        is_finished;
} t_game;

#endif