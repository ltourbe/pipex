/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltourbe <ltourbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:38:15 by ltourbe           #+#    #+#             */
/*   Updated: 2026/01/07 18:36:36 by ltourbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "pipex.h"

char	**find_path(char **envp)
{
	char	**paths;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			break ;
		envp++;
	}
	paths = ft_split(*envp + 5, ':');
	return (paths);
}

char	*good_path(char *command, char **maybe)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (maybe[i])
	{
		temp = ft_strjoin(maybe[i], "/");
		path = ft_strjoin(temp, command);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	first_exec(int fd[2], char *cmd, char *file, char **envp)
{
	char	**args;
	char	**path;
	int		infile;

	infile = open(file, O_RDONLY);
	if (infile == -1)
	{
		ft_printf("Error opening input file\n");
		return ;
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(infile);
	close(fd[0]);
	close(fd[1]);
	path = find_path(envp);
	args = ft_split(cmd, ' ');
	args[0] = good_path(args[0], path);
	if (args[0] == NULL)
	{
		ft_printf("command not found");
		return ;
	}
	execve(args[0], args, envp);
}

void	second_exec(int fd[2], char *cmd, char *file, char **envp)
{
	int		outfile;
	char	**args;
	char	**path;

	outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		ft_printf("Error opening output file\n");
		return ;
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	path = find_path(envp);
	args = ft_split(cmd, ' ');
	args[0] = good_path(args[0], path);
	if (args[0] == NULL)
	{	
		ft_printf("command not found");
		return ;
	}
	execve(args[0], args, envp);
}

int	main(int ac, char **av, char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 < 0)
			return (2);
		if (pid1 == 0)
			first_exec(fd, av[2], av[1], envp);
		pid2 = fork();
		if (pid2 < 0)
			return (3);
		if (pid2 == 0)
			second_exec(fd, av[3], av[4], envp);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		ft_printf("Wrong number of arguments");
}
