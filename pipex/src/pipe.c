/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:34:39 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/21 09:54:15 by mszymcza         ###   ########.fr       */
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

void	child(char **argv, char **envp, int *fd)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY, 0777);
	if (file_in == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent(char **argv, char **envp, int *fd)
{
	int	file_in;

	file_in = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_in == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file_in, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("There is an Error\n", 2);
	}
	return (0);
}
