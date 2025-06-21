/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:20:55 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/21 10:28:33 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_tile *map, int width, int height, char c)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < height)
	{
		while (x < width)
		{
			switch (map[y *width + x])
			{
				case TILE_WALL:			c = '1'; break;
				case TILE_START:		c = 'P'; break;
				case TILE_EXIT:			c = 'E'; break;
				case TILE_ITEM:			c = 'C'; break;
				case TILE_EMPTY:		c = '0'; 
			}
			ft_printf("%c", c);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long map.ber\n"), 1);

	game.map = read_map(argv[1], &game.width, &game.height);
	if (!game.map)
		return (ft_printf("Error: Invalid map\n"), 1);

	if (!validate_map(game.map, game.width, game.height))
		return (free(game.map), ft_printf("Error: Map validation failed\n"), 1);

	print_map(game.map, game.width, game.height);
	free(game.map);
	return (0);
}
