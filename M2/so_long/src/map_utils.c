/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:28:01 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:59:19 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_tile *map, int width, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			printf("%c", tile_to_char(map[y * width + x]));
			x++;
		}
		printf("\n");
		y++;
	}
}

static int	open_map_file(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

static int	read_map_lines(t_check *map, int fd, int height)
{
	char	*line;
	int		i;

	i = 0;
	map->map = ft_calloc(height + 1, sizeof(char *));
	if (!map->map)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	return (1);
}

int	copy_map_check(t_game *game, t_check *map, char *map_file)
{
	int	fd;

	map->width = game->width;
	map->height = game->height;
	fd = open_map_file(map_file);
	if (fd < 0)
		return (0);
	if (!read_map_lines(map, fd, game->height))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
