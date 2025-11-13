/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_color_to_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:08:17 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:41 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

unsigned int	rlx_color_to_uint(t_color color)
{
	return ((color.a << 24) + (color.r << 16) + (color.g << 8) + color.b);
}
