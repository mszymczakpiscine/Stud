/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:19:57 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/19 15:13:17 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("\033[1;31mError\n\033[0m");
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*find_path(char *cmb, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmb);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_tab(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_tab(paths);
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		free_tab(args);
		error();
	}
	path = find_path(args[0], envp);
	if (!path)
	{
		free_tab(args);
		ft_putstr_fd("Error : command not found\n", 2);
		exit(EXIT_FAILURE);
	}
	if (execve(path, args, envp) == -1)
	{
		free(path);
		free_tab(args);
		error();
	}
}

int	get_line(char **line)
{
	char	*buffer;
	int		i;
	int		c;
	int		j;

	i = 0;
	j = 1;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	while (j && (c = read(0, &buffer[i], 1)) > 0 && (buffer[i] != '\n'))
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;
	return (i);
}
