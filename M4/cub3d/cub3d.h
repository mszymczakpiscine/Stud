/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:55:21 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/21 14:55:21 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "rlx.h"
# include <bits/types/struct_timeval.h>
# include <stdbool.h>

typedef enum e_err
{
	ERR_OK,
	ERR_FAILED,
	ERR_SYSTEM,
	ERR_CONTINUE,
	ERR_BREAK,
}					t_err;

typedef enum e_tile
{
	TILE_EMPTY = 0,
	TILE_WALL,
	TILE_FLOOR,
	TILE_ITEM,
	TILE_EXIT,
	TILE_EAST,
	TILE_SOUTH,
	TILE_WEST,
	TILE_NORTH,
	TILE_ENEMY,
	TILE_SPACE,
	TILE_INVALID
}					t_tile;

typedef struct s_player
{
	t_vec2			position;
	float			angle;
	float			fov;
}					t_player;

typedef struct s_game
{
	t_rlx			rlx;
	struct timeval	last_frame;
	t_player		player;
	int				width;
	int				height;
	t_tile			*map;
	t_img			texture_north;
	t_img			texture_south;
	t_img			texture_east;
	t_img			texture_west;
	t_color			color_floor;
	t_color			color_ceiling;
}					t_game;

typedef struct s_lines
{
	int				fd;
	char			*last;
	char			*peek;
}					t_lines;

typedef struct s_metadata
{
	bool		is_set;
	char		*id;
	bool		is_color;
	union		u_metadata
	{
		t_img	*img;
		t_color	*color;
	} out;
}				t_metadata;

typedef struct s_ray
{
	t_vec2			origin;
	float			angle;
}					t_ray;

# ifndef RAY_MAX_STEPS
#  define RAY_MAX_STEPS 64
# endif

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}					t_direction;

typedef struct s_ray_hit
{
	t_vec2			location;
	float			distance;
	t_direction		face_direction;
	float			face_hit_pos;
}					t_ray_hit;

typedef struct s_position
{
	size_t			x;
	size_t			y;
}					t_position;

t_lines				lines_new(int fd);
void				lines_destroy(t_lines *lines);
char				*lines_next(t_lines *lines);
char				*lines_peek(t_lines *lines);

bool				has_cub_extension(const char *filename);
t_err				init(t_game *game, char *map_file);
t_err				skip_metadata(t_lines *lines);
t_err				get_dimensions(char *file, int *width, int *height);
t_err				parse_metadata(t_game *game, t_lines *lines);
t_err				parse_image(t_rlx *rlx, t_img *out, char *source);
t_err				parse_color(t_color *out, char *source);
t_err				parse_tiles(t_game *game, t_lines *lines);
bool				flood_fill(t_game *game);

t_tile				char_to_tile(char c);
char				tile_to_char(t_tile tile);

void				handle_input(t_game *game);

void				render_environment(t_game *game);
bool				cast_ray_h(t_ray ray, t_game *game, t_ray_hit *out);
bool				cast_ray_v(t_ray ray, t_game *game, t_ray_hit *out);

t_position			get_tile_pos(float x, float y, t_direction face_direction);
int					signum(float val);
t_img				*direction_to_img(t_game *game, t_direction direction);
t_color				get_color(t_img *img, size_t x, size_t y);

bool				str_isdigit(char *s);

#endif // !CUB3D_H
