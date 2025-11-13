#	PROGRAM NAME AND SOURCE FILES

NAME = librlx.a

SRCS = \
	rlx_camera_get_forward.c \
	rlx_camera_get_up.c \
	rlx_camera_get_right.c \
	rlx_close.c \
	rlx_color_from_uint.c \
	rlx_color_lerp.c \
	rlx_color_rgb.c \
	rlx_color_rgba.c \
	rlx_color_to_uint.c \
	rlx_destroy_image.c \
	rlx_draw_begin.c \
	rlx_draw_end.c \
	rlx_draw_pixel.c \
	rlx_draw_pixel_depth.c \
	rlx_draw_pixel_unchecked.c \
	rlx_draw_pixel_xy.c \
	rlx_draw_rect.c \
	rlx_frame_begin.c \
	rlx_frame_end.c \
	rlx_get_world_to_screen.c \
	rlx_init.c \
	rlx_is_key_down.c \
	rlx_is_key_pressed.c \
	rlx_lerp.c \
	rlx_load_image.c \
	rlx_loop.c \
	rlx_loop_end.c \
	rlx_matrix_identity.c \
	rlx_matrix_lookat.c \
	rlx_matrix_ortho.c \
	rlx_matrix_perspective.c \
	rlx_quat_from_axis_angle.c \
	rlx_quat_from_vec3.c \
	rlx_quat_identity.c \
	rlx_quat_mul.c \
	rlx_quat_normalize.c \
	rlx_quat_to_euler.c \
	rlx_quat_transform.c \
	rlx_vec2_distance.c \
	rlx_vec2_dotproduct.c \
	rlx_vec2_from_vec3.c \
	rlx_vec2_length.c \
	rlx_vec2_lerp.c \
	rlx_vec2_normalize.c \
	rlx_vec2_sub.c \
	rlx_vec2_project.c \
	rlx_vec2_zero.c \
	rlx_vec3_add.c \
	rlx_vec3_crossproduct.c \
	rlx_vec3_dotproduct.c \
	rlx_vec3_forward.c \
	rlx_vec3_from_quat.c \
	rlx_vec3_length.c \
	rlx_vec3_lerp.c \
	rlx_vec3_normalize.c \
	rlx_vec3_one.c \
	rlx_vec3_right.c \
	rlx_vec3_rotate_by_quat.c \
	rlx_vec3_scale.c \
	rlx_vec3_sub.c \
	rlx_vec3_up.c \
	rlx_vec3_zero.c \
	rlx_window_background_clear.c \
	rlx_window_close.c \
	rlx_window_init.c \

#	CONFIG

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
OBJS_PATH = objs/

LIBMLX_PATH = ../minilibx-linux/
IFLAGS += -I$(LIBMLX_PATH)

#	VARS

OBJS = $(addprefix $(OBJS_PATH), ${SRCS:.c=.o})

#	RULES

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) -r $(NAME) $?

$(OBJS_PATH)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $? -o $@

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
