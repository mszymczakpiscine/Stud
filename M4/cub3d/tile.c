/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:59:00 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/21 15:04:09 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tile	char_to_tile(char c)
{
	if (c == '0')
		return (TILE_EMPTY);
	if (c == '1')
		return (TILE_WALL);
	if (c == 'N')
		return (TILE_NORTH);
	if (c == 'S')
		return (TILE_SOUTH);
	if (c == 'E')
		return (TILE_EAST);
	if (c == 'W')
		return (TILE_WEST);
	if (c == ' ')
		return (TILE_SPACE);
	return (TILE_INVALID);
}

char	tile_to_char(t_tile tile)
{
	if (tile == TILE_WALL)
		return ('1');
	if (tile == TILE_NORTH)
		return ('N');
	if (tile == TILE_SOUTH)
		return ('S');
	if (tile == TILE_EAST)
		return ('E');
	if (tile == TILE_WEST)
		return ('W');
	if (tile == TILE_SPACE)
		return (' ');
	return ('0');
}
