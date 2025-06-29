/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:54:13 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/18 13:54:13 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_tile	char_to_tile(char c)
{
	if (c == '0')
		return (TILE_EMPTY);
	if (c == '1')
		return (TILE_WALL);
	if (c == 'C')
		return (TILE_ITEM);
	if (c == 'E')
		return (TILE_EXIT);
	if (c == 'P')
		return (TILE_START);
	return (TILE_INVALID);
}
