/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_window_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:18:01 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:59 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librlx.h"
#include "mlx.h"
#include <stdlib.h>

static int	key_press(int keycode, t_input *input)
{
	size_t	i;

	if (input->n_keys >= RLX_MAX_KEYS)
		return (0);
	i = 0;
	while (i < input->n_keys)
	{
		if (input->keys[i] == keycode)
			return (0);
		i++;
	}
	input->keys[input->n_keys] = keycode;
	input->n_keys++;
	return (0);
}

static int	key_release(int keycode, t_input *input)
{
	size_t	i;

	if (input->n_keys == 0)
		return (0);
	input->n_keys--;
	i = 0;
	while (i < input->n_keys)
	{
		if (input->keys[i] == keycode)
		{
			while (i < input->n_keys)
			{
				input->keys[i] = input->keys[i + 1];
				i++;
			}
			break ;
		}
		i++;
	}
	return (0);
}

static int	exit_hook(t_rlx *rlx)
{
	mlx_loop_end(rlx->mlx);
	return (0);
}

void	rlx_window_init(t_rlx *rlx, unsigned int width, unsigned int height)
{
	rlx->window.is_ready = false;
	rlx->window.width = width;
	rlx->window.height = height;
	rlx->window.ptr = mlx_new_window(rlx->mlx, width, height, "fdf");
	if (!rlx->window.ptr)
		return (rlx_window_close(rlx));
	rlx->window.img.data = mlx_new_image(rlx->mlx, width, height);
	if (!rlx->window.img.data)
		return (rlx_window_close(rlx));
	rlx->window.img.addr = mlx_get_data_addr(rlx->window.img.data,
			&rlx->window.img.bits_per_pixel, &rlx->window.img.line_length,
			&rlx->window.img.endian);
	if (!rlx->window.img.addr)
		return (rlx_window_close(rlx));
	rlx->window.img.z_buffer = (float *)malloc(sizeof(float) * width * height);
	if (!rlx->window.img.z_buffer)
		return (rlx_window_close(rlx));
	rlx->window.input.n_keys = 0;
	mlx_hook(rlx->window.ptr, 17, 0, exit_hook, rlx);
	mlx_hook(rlx->window.ptr, 2, 1L << 0, key_press, &rlx->window.input);
	mlx_hook(rlx->window.ptr, 3, 1L << 1, key_release, &rlx->window.input);
	rlx->window.is_ready = true;
	return ;
}
