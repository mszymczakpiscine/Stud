/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:10:00 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:53:21 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRLX_H
# define LIBRLX_H

# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>

# define RLX_DEG2RAD 0.01745329251994329577
# define RLX_RAD2DEG 57.2957795130823208768

# define RLX_Z_BUFFER_DEPTH UINT_MAX

# define RLX_CAMERA_NEAR 0.01
# define RLX_CAMERA_FAR 1000.0

# define RLX_MAX_KEYS 16

# define BLACK 0xFF000000
# define WHITE 0xFFFFFFFF
# define RED 0xFFFF0000
# define GREEN 0xFF00FF00
# define BLUE 0xFF0000FF

typedef struct s_color
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_vec2
{
	float			x;
	float			y;
}					t_vec2;

typedef struct s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct s_quat
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_quat;

typedef struct s_matrix
{
	float			m0;
	float			m1;
	float			m2;
	float			m3;
	float			m4;
	float			m5;
	float			m6;
	float			m7;
	float			m8;
	float			m9;
	float			m10;
	float			m11;
	float			m12;
	float			m13;
	float			m14;
	float			m15;
}					t_matrix;

typedef struct s_tri
{
	t_vec3			a;
	t_vec3			b;
	t_vec3			c;
}					t_tri;

typedef struct s_img
{
	void			*data;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	float			*z_buffer;
}					t_img;

typedef enum e_projection
{
	RLX_CAMERA_ISOMETRIC = 0,
	RLX_CAMERA_PERSPECTIVE,
}					t_projection;

typedef struct s_camera
{
	t_vec3			position;
	t_quat			rotation;
	t_vec3			up;
	float			fov;
	t_projection	projection;
}					t_camera;

typedef struct s_input
{
	size_t			n_keys;
	int				keys[RLX_MAX_KEYS];
	size_t			prev_n_keys;
	int				prev_keys[RLX_MAX_KEYS];
}					t_input;

typedef struct s_window
{
	bool			is_ready;
	void			*ptr;
	t_img			img;
	unsigned int	width;
	unsigned int	height;
	t_input			input;
}					t_window;

typedef struct s_rlx
{
	bool			is_ready;
	void			*mlx;
	t_window		window;
}					t_rlx;

// RLX instance management
t_rlx				rlx_init(void);
void				rlx_close(t_rlx *rlx);
void				rlx_loop(t_rlx *rlx, int (*loop)(void *), void *state);
void				rlx_loop_end(t_rlx *rlx);

// Window management
void				rlx_window_init(t_rlx *rlx, unsigned int width,
						unsigned int height);
void				rlx_window_close(t_rlx *rlx);

// Frame
void				rlx_frame_begin(t_rlx *rlx);
void				rlx_frame_end(t_rlx *rlx);

// Input
bool				rlx_is_key_down(t_window *window, int keycode);
bool				rlx_is_key_pressed(t_window *window, int keycode);

// Camera
t_camera			rlx_camera_new(void);
t_vec3				rlx_camera_get_forward(t_camera *camera);
t_vec3				rlx_camera_get_up(t_camera *camera);
t_vec3				rlx_camera_get_right(t_camera *camera);

// Screen-space
t_vec3				rlx_get_world_to_screen(t_window *window, t_camera *camera,
						t_vec3 point);

// Drawing
void				rlx_window_background_clear(t_window *window,
						t_color color);

// Shapes
void				rlx_draw_begin(t_rlx *rlx);
void				rlx_draw_end(t_rlx *rlx);
void				rlx_draw_pixel(t_window *window, t_vec2 p, t_color color);
void				rlx_draw_pixel_depth(t_window *window, t_vec2 p,
						t_color color, float depth);
void				rlx_draw_pixel_xy(t_window *window, size_t x, size_t y,
						t_color color);
void				rlx_draw_pixel_unchecked(t_window *window, size_t x,
						size_t y, t_color color);

// Color
t_color				rlx_color_rgb(unsigned char r, unsigned char g,
						unsigned char b);
t_color				rlx_color_rgba(unsigned char r, unsigned char g,
						unsigned char b, unsigned char a);
t_color				rlx_color_from_uint(unsigned int color);
unsigned int		rlx_color_to_uint(t_color color);
t_color				rlx_color_lerp(t_color from, t_color to, float factor);

// Scalar math
float				rlx_lerp(float from, float to, float factor);

// 2D vector math
t_vec2				rlx_vec2_zero(void);
t_vec2				rlx_vec2_one(void);
t_vec2				rlx_vec2_new(float x, float y);
t_vec2				rlx_vec2_from_vec3(t_vec3 vec);
t_vec2				rlx_vec2_lerp(t_vec2 from, t_vec2 to, float factor);

// 3D vector math
t_vec3				rlx_vec3_zero(void);
t_vec3				rlx_vec3_one(void);
t_vec3				rlx_vec3_forward(void);
t_vec3				rlx_vec3_up(void);
t_vec3				rlx_vec3_right(void);
t_vec3				rlx_vec3_from_quat(t_quat quat);
t_vec3				rlx_vec3_add(t_vec3 a, t_vec3 b);
t_vec3				rlx_vec3_sub(t_vec3 a, t_vec3 b);
t_vec3				rlx_vec3_scale(t_vec3 u, float f);
t_vec3				rlx_vec3_normalize(t_vec3 u);
t_vec3				rlx_vec3_crossproduct(t_vec3 u, t_vec3 v);
float				rlx_vec3_dotproduct(t_vec3 u, t_vec3 v);
float				rlx_vec3_length(t_vec3 u);
t_vec3				rlx_vec3_rotate_by_quat(t_vec3 u, t_quat q);

// Quaternion math
t_quat				rlx_quat_from_vec3(t_vec3 vec);
t_quat				rlx_quat_mul(t_quat q, t_quat p);
t_quat				rlx_quat_tranform(t_quat quat, t_matrix mat);
t_quat				rlx_quat_identity(void);
t_quat				rlx_quat_normalize(t_quat q);
t_quat				rlx_quat_from_axis_angle(t_vec3 axis, float angle);
t_vec3				rlx_quat_to_euler(t_quat q);

// Matrix (4x4) math
t_matrix			rlx_matrix_ortho(float right, float top, float near,
						float far);
t_matrix			rlx_matrix_perspective(float fovY, float aspect, float near,
						float far);
t_matrix			rlx_matrix_lookat(t_vec3 position, t_vec3 target,
						t_vec3 up);

#endif // LIBRLX_H
