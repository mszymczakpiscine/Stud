/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:24:30 by aheisch           #+#    #+#             */
/*   Updated: 2025/11/03 15:24:30 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

t_err	get_dimensions(char *file, int *width, int *height)
{
	int		fd;
	t_lines	lines;
	char	*line;
	size_t	len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ERR_SYSTEM);
	lines = lines_new(fd);
	skip_metadata(&lines);
	*width = 0;
	*height = 0;
	while (true)
	{
		line = lines_next(&lines);
		if (!line || line[0] == '\n')
			break ;
		len = ft_strlen(line) - 1;
		if (*width < (int)len)
			*width = len;
		(*height)++;
	}
	return (lines_destroy(&lines), ERR_OK);
}
