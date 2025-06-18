/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:36:41 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/18 19:42:07 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h> 

void	error(void);
void	free_tab(char **tab);
//char	*find_path(char *cmd, char **envp);
void	execute(char *cmd, char **envp);
void	child(char **argv, char **envp, int *fd);
void	parent(char **argv, char **envp, int *fd);
//int		get_line(char **line);

#endif

//./pipex infile "cat src/pipe.c"  "grep ' '" outfile
//gestion des single quotes