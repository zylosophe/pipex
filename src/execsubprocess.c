/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execsubprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:49:13 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/21 16:09:00 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "error.h"

void	execsubprocess(int readfd, int writefd, t_string *argv)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		errorandstop("pipex");
	if (!pid)
	{
		if (dup2(readfd, 0) == -1
			|| dup2(writefd, 1) == -1)
			errorandstop("pipex");
		execve(argv[0], argv, NULL);
		errorandstop(argv[0]);
	}
	if (close(readfd) == -1
		|| close(writefd) == -1)
		errorandstop("pipex");
}
