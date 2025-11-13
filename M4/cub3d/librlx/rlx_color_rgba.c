/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlx_color_rgba.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:29:08 by aheisch           #+#    #+#             */
/*   Updated: 2025/05/27 15:52:39 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rlx.h"

t_color	rlx_color_rgba(unsigned char r, unsigned char g, unsigned char b,
		unsigned char a)
{
	return ((t_color){
		.a = a,
		.r = r,
		.g = g,
		.b = b,
	});
}
