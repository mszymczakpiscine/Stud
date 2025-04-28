/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:28:21 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/28 15:37:21 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
