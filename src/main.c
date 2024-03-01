/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:55 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/01 11:32:02 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include "error.h"
#include "libtf.h"
#include "execcommand.h"
#include "pipe.h"
#include "heredoc.h"

static t_pipe	*create_pipes(
	int is_heredoc, int size, t_const_string rfile, t_const_string wfile)
{
	t_pipe	*r;
	int		i;
	int		wfile_flag;

	wfile_flag = O_TRUNC;
	if (is_heredoc)
		wfile_flag = O_APPEND;
	r = mem_alloc(err, get_mc(), (size) * sizeof(t_pipe));
	if (is_heredoc)
		heredoc(&r[0][0], rfile);
	else
		r[0][0] = open(rfile, O_RDONLY);
	if (r[0][0] == -1)
		errorandstop(rfile);
	i = 0;
	while (++i < size - 1)
		if (pipe(r[i]) == -1)
			err(NULL);
	r[i][1] = open(wfile, O_WRONLY | O_CREAT | wfile_flag, 0666);
	if (r[i][1] == -1)
		errorandstop(wfile);
	return (r);
}

static int	booltoint(bool v)
{
	if (v)
		return (1);
	return (0);
}

int	main(int argc, t_const_string argv[], t_const_string envp[])
{
	t_pipe		*pipes;
	int			i;
	const int	is_heredoc = booltoint(argc > 1 && str_eq(argv[1], "here_doc"));
	const int	size_pipes = argc - 2 - is_heredoc;
	const int	nb_subprocess = argc - 3 - is_heredoc;

	startprogram(argv[0]);
	if (argc < 5 + is_heredoc)
	{
		print_str(err, 2, argv[0]);
		print_line(err, 2, ": takes at least 4 arguments (5 with here_doc).");
		endprogram(1);
	}
	pipes = create_pipes(
			is_heredoc, size_pipes, argv[1 + is_heredoc], argv[argc - 1]);
	i = -1;
	while (++i < nb_subprocess)
		execcommand(
			pipes[i][0], pipes[i + 1][1], argv[i + 2 + is_heredoc], envp);
	while (wait(NULL) != -1)
		;
	if (errno != ECHILD)
		err(NULL);
	endprogram(0);
}
