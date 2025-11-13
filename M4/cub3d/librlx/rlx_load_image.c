/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_load_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:28:40 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/28 15:28:40 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rlx.h"
#include <stdio.h>

t_img	rlx_load_image(t_rlx *rlx, char *filename)
{
	t_img	img;

	img.data = mlx_xpm_file_to_image(rlx->mlx, filename, &img.width,
			&img.height);
	if (!img.data)
		return (img);
	img.addr = mlx_get_data_addr(img.data, &img.bits_per_pixel, &img.width,
			&img.endian);
	if (!img.addr)
		return (img);
	img.z_buffer = NULL;
	return (img);
}
