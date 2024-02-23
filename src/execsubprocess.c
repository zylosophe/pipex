/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execsubprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:49:13 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/22 15:20:41 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "execfrompath.h"
#include "error.h"

void	execsubprocess(
	int readfd, int writefd, t_string argv[], t_const_string envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		err(NULL);
	if (!pid)
	{
		if (dup2(readfd, 0) == -1
			|| dup2(writefd, 1) == -1)
			err(NULL);
		execfrompath(argv, envp);
	}
	if (close(readfd) == -1
		|| close(writefd) == -1)
		err(NULL);
}
