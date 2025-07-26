/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:43:29 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:09:40 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_check *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (1);
	if (map->map[y][x] == '1' || map->map[y][x] == 'c')
		return (1);
	else
		map->map[y][x] = 'c';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	return (0);
}

void	free_check_map(t_check *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map->map && map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

int	check_after_filled(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				write(2, "Error:\nMap can't be finished\n", 29);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
