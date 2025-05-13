/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:17:07 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/13 17:53:23 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	int	fd;
	char	*line;

	fd = open("/home/mszymcza/francinette/tests/get_next_line/gnlTester/files/nl", O_RDONLY);
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
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}
