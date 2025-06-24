/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:34:39 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/23 11:17:07 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	file_in = open(argv[1], O_RDONLY, 0644);
	if (file_in == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file_in);
	execute(argv[2], envp);
}

void	parent(char **argv, char **envp, int *fd)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(file_out);
	execute(argv[3], envp);
}

static pid_t	safe_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error();
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = safe_fork();
		if (pid1 == 0)
			child(argv, envp, fd);
		pid2 = safe_fork();
		if (pid2 == 0)
			parent(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		ft_putstr_fd("There is an Error\n", 2);
	return (0);
}
