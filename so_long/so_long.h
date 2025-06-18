/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:12 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/17 14:34:04 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef enum	e_tile
{
	TILE_EMPTY = 0, 
	TILE_WALL,
	TILE_ITEM,
	TILE_EXIT,
	TILE_START,
	TILE_MOB,

}	t_tile;

#endif