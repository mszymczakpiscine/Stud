/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:27:35 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/26 11:41:42 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_tile *map)
{
	if (map)
		free(map);
}

static int	read_char_to_tile(int fd, t_map_read_context *ctx, int *i)
{
	char	c;
	int		val_return;

	val_return = read(fd, &c, 1);
	while (val_return > 0 && c == '\n')
	{
		val_return = read(fd, &c, 1);
	}
	if (val_return <= 0)
		return (0);
	if (*i >= ctx->width * ctx->height)
		return (0);
	ctx->map[*i] = char_to_tile(c);
	if (ctx->map[*i] == TILE_START)
	{
		ctx->game->player_x = *i % ctx->width;
		ctx->game->player_y = *i / ctx->width;
	}
	if (ctx->map[*i] == TILE_INVALID)
		return (-1);
	(*i)++;
	return (1);
}

static int	read_map_loop(int fd, t_map_read_context *ctx)
{
	int	i;
	int	ret;

	i = 0;
	ret = read_char_to_tile(fd, ctx, &i);
	while (ret > 0)
	{
		ret = read_char_to_tile(fd, ctx, &i);
	}
	if (ret == -1)
		return (-1);
	if (i != ctx->width * ctx->height)
		return (-1);
	return (0);
}

t_tile	*read_map(char *file_in, int width, int height, t_game *game)
{
	int					fd;
	t_tile				*map;
	t_map_read_context	ctx;

	if (height <= 0 || width <= 0)
		return (NULL);
	map = malloc(sizeof(t_tile) * (width * height));
	if (!map)
		return (NULL);
	fd = open(file_in, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	ctx.map = map;
	ctx.width = width;
	ctx.height = height;
	ctx.game = game;
	if (read_map_loop(fd, &ctx) == -1)
	{
		close(fd);
		free(map);
		return (NULL);
	}
	close(fd);
	return (map);
}

int	has_ber_extension(const char *filename)
{
	size_t	len;

	len = strlen(filename);
	if (len < 5)
		return (0);
	return (strcmp(filename + len - 4, ".ber") == 0);
}
