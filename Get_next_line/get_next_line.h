/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:34:36 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/13 17:29:46 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500
#endif

char	*get_next_line(int fd);
int		read_and_stock(int fd, char **stock);
char	*extract_line(const char *stock);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	update_stock(char **stock, const char *line);

#endif

