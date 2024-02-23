/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execfrompath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:10:25 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/23 16:50:22 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "libtf.h"
#include "error.h"

static t_const_string	getpath(t_const_string envp[])
{
	const t_const_string	search = "PATH=";
	int						i;
	int						j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (!search[j])
			return (envp[i] + j);
		if (envp[i][j] != search[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	errno = 1;
	err(NULL);
	return (NULL);
}

void	execfrompath(t_string argv[], t_const_string envp[])
{
	const t_memclass		mc = mem_newclass(err);
	const t_string			*paths = str_split(err, mc, getpath(envp), ":");
	int						i;

	if (char_isin('/', argv[0]))
	{
		execve(argv[0], argv, NULL);
		mem_freeall(mc);
		errorandstop(argv[0]);
	}
	i = -1;
	while (paths[++i])
	{
		execve(
			str_join(err, mc, paths[i], str_join(err, mc, "/", argv[0])),
			argv, NULL);
		if (errno != 2)
		{
			mem_freeall(mc);
			errorandstop(argv[0]);
		}
	}
	mem_freeall(mc);
	err_commandnotfound(argv[0]);
}
