/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:20:55 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/29 10:22:23 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_tile *map, int width, int height, char c)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y * width + x] == TILE_WALL)
				c = '1';
			else if (map[y * width + x] == TILE_START)
				c = 'P';
			else if (map[y * width + x] == TILE_EXIT)
				c = 'E';
			else if (map[y * width + x] == TILE_ITEM)
				c = 'C';
			else if (map[y * width + x] == TILE_EMPTY)
				c = '0';
			ft_printf("%c", c);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

int	validate_map_elements(t_game *game)
{
	return (validate_map(game->map, game->width, game->height));
}

void	exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	check_map(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
		exit_error("Error\nyou need a .ber extension!");
	if (open(file, O_RDONLY) < 0)
		exit_error("Error\nfile not found");
	return (1);
}

void parse_map(t_game *game, char *file) 
{
    check_map(file);
    game->map = read_map(file, &game->width, &game->height, game);
    if (!game->map)
        exit_error("Error\nFailed to read map");
    if (!validate_map_elements(game))
        exit_error("Error\nInvalid map");
}

