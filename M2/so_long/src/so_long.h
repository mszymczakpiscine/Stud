/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:57:55 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 12:32:23 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# define TILE_SIZE 64
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_ESC 65307
# define MAX_MAP_WIDTH 30
# define MAX_MAP_HEIGHT 16

typedef struct s_game	t_game;

typedef enum e_tile
{
	TILE_EMPTY = 0,
	TILE_WALL,
	TILE_FLOOR,
	TILE_ITEM,
	TILE_EXIT,
	TILE_START,
	TILE_ENEMY,
	TILE_INVALID
}	t_tile;

typedef struct s_map_read_context
{
	t_tile	*map;
	int		width;
	int		height;
	t_game	*game;
}	t_map_read_context;

typedef struct s_img
{
	void	*data;
}	t_img;

typedef struct s_counters
{
	int	player;
	int	exit;
	int	item;
}	t_counters;

typedef struct s_map_size
{
	int	w;
	int	h;
}	t_map_size;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_size
{
	int	w;
	int	h;
}	t_size;

typedef struct s_check
{
	char	**map;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_check;

typedef struct s_window
{
	void			*ptr;
	t_img			img;
	unsigned int	width;
	unsigned int	height;
}	t_window;

typedef struct s_game
{
	void		*mlx;
	t_window	window;
	t_tile		*map;
	int			width;
	int			height;
	int			enemy_x;
	int			enemy_y;
	int			enemy_dir;
	int			frame_count;
	int			needs_redraw;
	t_img		wall;
	t_img		player;
	t_img		exit;
	t_img		collect;
	t_img		floor;
	t_img		enemy;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			collected;
	int			steps;
	int			fps;
}	t_game;

int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
void	move_player(t_game *game, int keycode);
void	put_tile(t_game *game, t_img img, int x, int y);
void	move_enemy_towards_player(t_game *game);
void	render_map(t_game *game);
void	free_map(t_tile *map);
void	put_steps_to_screen(t_game *game);
int		check_after_filled(char **map);
int		flood_fill(t_check *map, int x, int y);
int		copy_map_check(t_game *game, t_check *map, char *map_file);
int		render_frame(t_game *game);
int		close_game(t_game *game);
int		start_game(t_game *game, char *map_file);
int		has_ber_extension(const char *filename);
int		validate_map(t_tile *map, int width, int height);
t_tile	*read_map(char *file_in, int width, int height, t_game *game);
void	print_map(t_tile *map, int width, int height);
void	init_enemy_position(t_game *game);
t_tile	char_to_tile(char c);
int		count_line(char *file);
int		tile_count(char *file);
int		col_count(char *file);
int		handle_input(int keycode, t_game *game);
void	free_check_map(t_check *map);
void	check_images(t_game *game);
void	load_images(t_game *game);
void	count_collectibles(t_game *game);
int		check_map_dimensions(t_game *game, char *map_file);
int		load_game_map(t_game *game, char *map_file);
int		render_frame(t_game *game);
int		init_game(t_game *game, char *map_file);
int		init_window_and_images(t_game *game);
int		start_game(t_game *game, char *map_file);
int		ft_abs(int nb);
void	render_tiles(t_game *game);
void	end_game(t_game *game);
char	tile_to_char(t_tile tile);
int		check_tiles(t_tile *map, int w, int h);

#endif
