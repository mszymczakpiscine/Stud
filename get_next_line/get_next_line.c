/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:28:21 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/30 10:23:02 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_and_stock(int fd, char **stock)
{
	char	*buffer;
	size_t	read_bytes;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!strchr(*stock, '\n') && (read_bytes = read(fd, stock, BUFFER_SIZE) > 0))
		buffer[read_bytes] = '\0';
	
			
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock && read_and_stock())
		return (NULL);
	line = extract_line();
	if (!line)
		return (NULL);
	update_stock();
	return (stock);
}
