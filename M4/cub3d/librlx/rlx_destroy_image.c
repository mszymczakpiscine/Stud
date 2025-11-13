/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:05:25 by aheisch           #+#    #+#             */
/*   Updated: 2025/10/29 19:05:25 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rlx.h"

void	rlx_destroy_image(t_rlx *rlx, t_img *img)
{
	mlx_destroy_image(rlx->mlx, img->data);
}
