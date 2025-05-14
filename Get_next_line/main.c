/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:17:07 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/14 21:40:03 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("get_next_line.c", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur lors de l'ouverture");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("\e[44m%d|\e[0m\e[38;5;213m%s\e[0m\n", i++, line);
		free(line);
	}
	close(fd);
	return (0);
}

