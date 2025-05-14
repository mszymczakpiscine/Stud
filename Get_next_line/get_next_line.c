/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:28:21 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/14 21:23:21 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_and_read(int fd, char **stock)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*tmp;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (free(*stock), *stock = NULL, -1);
	buffer[read_bytes] = '\0';
	tmp = *stock;
	*stock = ft_strjoin(*stock, buffer);
	free(tmp);
	if (!*stock)
		return (-1);
	return (read_bytes);
}

int	read_and_stock(int fd, char **stock)
{
	int	read_bytes;

	if (!*stock)
	{
		*stock = malloc(1);
		if (!*stock)
			return (-1);
		*stock[0] = '\0';
	}
	while (!ft_strchr(*stock, '\n'))
	{
		read_bytes = read_and_read(fd, stock);
		if (read_bytes < 0)
			return (-1);
		if (read_bytes < BUFFER_SIZE)
			break ;
	}
	return (0);
}

// int	read_and_stock(int fd, char **stock)
// {
// 	char	buffer[BUFFER_SIZE + 1];
// 	int		read_bytes;
// 	char	*tmp;

// 	if (!*stock)
// 	{
// 		*stock = malloc(1);
// 		if (!*stock)
// 			return (-1);
// 		*stock[0] = '\0';
// 	}
// 	while (!ft_strchr(*stock, '\n'))
// 	{
// 		read_bytes = read(fd, buffer, BUFFER_SIZE);
// 		if (read_bytes < 0)
// 		{
// 			if (*stock)
// 				free(*stock);
// 			*stock = NULL;
// 			return (-1);
// 		}
// 		buffer[read_bytes] = '\0';
// 		tmp = *stock;
// 		*stock = ft_strjoin(*stock, buffer);
// 		free(tmp);
// 		if (!*stock)
// 			return (-1);
// 		if (read_bytes < BUFFER_SIZE)
// 			break ;
// 	}
// 	return (0);
// }

char	*extract_line(const char *stock)
{
	char	*line;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!stock || !*stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stock[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

void	update_stock(char **stock)
{
	char	*new_stock;

	new_stock = ft_strchr(*stock, '\n');
	if (new_stock)
		new_stock = ft_strdup(new_stock + 1);
	free(*stock);
	*stock = new_stock;
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_and_stock(fd, &stock) < 0)
		return (NULL);
	line = extract_line(stock);
	if (!line)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	update_stock(&stock);
	return (line);
}
