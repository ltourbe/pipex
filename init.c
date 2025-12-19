/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltourbe <ltourbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:38:15 by ltourbe           #+#    #+#             */
/*   Updated: 2025/12/19 14:05:41 by ltourbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int ac, char **av, char *env[])
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	outfile;
	char	*cat_args[] = {"/usr/bin/cat", "-e", av[1], NULL};
	char	*wc_args[] = {"/usr/bin/wc", "-w", NULL};
	
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/cat", cat_args, env);
	}
	if (pid2 == 0)
	{
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT, 0777);
		if (outfile == -1)
			return (4);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(outfile);
		execve("/usr/bin/wc", wc_args, env);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
