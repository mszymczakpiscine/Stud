/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_metadata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheisch <aheisch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:26:11 by aheisch           #+#    #+#             */
/*   Updated: 2025/11/03 15:26:11 by aheisch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_err	skip_metadata(t_lines *lines)
{
	char	*line;

	while (true)
	{
		line = lines_peek(lines);
		if (!line)
			return (ERR_FAILED);
		if (line[0] == '\n' || ft_strncmp(line, "NO", 2) == 0
			|| ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
			|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "F", 1) == 0
			|| ft_strncmp(line, "C", 1) == 0)
		{
			lines_next(lines);
			continue ;
		}
		else
			break ;
	}
	return (ERR_OK);
}
