/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:28:01 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/21 15:27:48 by mszymcza         ###   ########.fr       */
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

int	count_line(char *file)
{
	int		fd;
	int		line = 0;
	char	c;
	int		val_return;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((val_return = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			line++;
	}
	close(fd);
	return (line);
}

int	tile_count(char *file)
{
	int		fd;
	int		count = 0;
	char	c;
	t_tile	tile;
	int		val_return;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((val_return = read(fd, &c, 1)) > 0)
	{
		tile = char_to_tile(c);
		if (tile == TILE_INVALID && c != '\n')
			return (close(fd), -1);
		if (c != '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	col_count(char *file)
{
	int		fd;
	int		col = 0;
	int		first_line = -1;
	char	c;
	int		val_return;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((val_return = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
		{
			if (first_line == -1)
				first_line = col;
			else if (col != first_line)
				return (close(fd), -1);
			col = 0;
			continue;
		}
		col++;
	}
	close(fd);
	if (first_line == -1)
        return col;
	return (first_line);
}

void	print_map(t_tile *map, int width, int height)
{
	char	c;
	int		y;
	int		x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			c = '0';
			if (map[y * width + x] == TILE_WALL)
				c = '1';
			else if (map[y * width + x] == TILE_START)
				c = 'P';
			else if (map[y * width + x] == TILE_EXIT)
				c = 'E';
			else if (map[y * width + x] == TILE_ITEM)
				c = 'C';
			else if (map[y * width + x] == TILE_ENEMY)
				c = 'X';
			printf("%c", c);
			x++;
		}
		printf("\n");
		y++;
	}
}

void init_enemy_position(t_game *game)
{
    int i;
    int map_size;

    if (!game->map)
    {
        write(2, "Error: map not loaded\n", 22);
        exit(EXIT_FAILURE);
    }

    map_size = game->width * game->height;

    for (i = 0; i < map_size; i++)
    {
        if (game->map[i] == TILE_ENEMY)
        {
            game->enemy_x = i % game->width;
            game->enemy_y = i / game->width;
            printf("Enemy found at (%d, %d)\n", game->enemy_x, game->enemy_y);
            return;
        }
    }
    game->enemy_x = 0;
    game->enemy_y = 0;
    printf("Enemy not found in map, default position used\n");
}

static int ft_abs(int nb){
	if(nb < 0)
		return (-nb);
	return (nb);
}

void	move_enemy_towards_player(t_game *game)
{
	int dx = game->player_x - game->enemy_x;
	int dy = game->player_y - game->enemy_y;
	int next_x = game->enemy_x;
	int next_y = game->enemy_y;

	if (game->enemy_x == -1 || game->enemy_y == -1)
		return;
	if (ft_abs(dx) > ft_abs(dy))
	{
		if (dx > 0)
			next_x += 1;
		else if (dx < 0)
			next_x -= 1;
		//usleep(160000);
	}
	else
	{
		if (dy > 0)
			next_y += 1;
		else if (dy < 0)
			next_y -= 1;
		//usleep(160000);
	}

	if (next_x >= 0 && next_x < game->width &&
		next_y >= 0 && next_y < game->height &&
		game->map[next_y * game->width + next_x] != TILE_WALL)
	{
		game->enemy_x = next_x;
		game->enemy_y = next_y;
		game->needs_redraw = 1;
		//usleep(160000);
	}
}
