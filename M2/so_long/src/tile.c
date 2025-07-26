/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:59:00 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:59:23 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (c == 'X')
		return (TILE_ENEMY);
	return (TILE_INVALID);
}

char	tile_to_char(t_tile tile)
{
	if (tile == TILE_WALL)
		return ('1');
	if (tile == TILE_START)
		return ('P');
	if (tile == TILE_EXIT)
		return ('E');
	if (tile == TILE_ITEM)
		return ('C');
	if (tile == TILE_ENEMY)
		return ('X');
	return ('0');
}
