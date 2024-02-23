/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:19:19 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/23 15:44:14 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipe.h"
#include "error.h"
#include "libtf.h"

static void	catcherror(int fd, t_const_string errmsg)
{
	if (!errmsg)
		return ;
	close(fd);
	err(NULL);
}

void	heredoc(int *readfd, t_const_string eof)
{
	t_pipe					outpipe;
	t_const_string			line;
	const t_const_string	eof_line = str_join(err, get_mc(), eof, "\n");

	if (pipe(outpipe) == -1)
		err(NULL);
	*readfd = outpipe[0];
	line = NULL;
	while (true)
	{
		mem_free((void *)line);
		print_str(err, 1, "( ^,^)> ");
		line = read_line(err_remember, get_mc(), 0);
		catcherror(outpipe[1], err_get());
		if (!line)
			continue ;
		if (str_eq(line, eof) || str_eq(line, eof_line))
			break ;
		print_str(err_remember, outpipe[1], line);
		catcherror(outpipe[1], err_get());
	}
	mem_free((void *)eof_line);
	close(outpipe[1]);
}
