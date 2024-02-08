/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:55 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/21 16:35:40 by mcolonna         ###   ########.fr       */
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

t_pipe	*create_pipes(int size, t_const_string rfile, t_const_string wfile)
{
	t_pipe	*r;
	int		i;

	r = mem_alloc(err, get_mc(), (size) * sizeof(t_pipe));
	r[0][0] = open(rfile, O_RDONLY);
	if (r[0][0] == -1)
		errorandstop(rfile);
	i = 0;
	while (++i < size - 1)
		if (pipe(r[i]) == -1)
			errorandstop("pipex");
	r[i][1] = open(wfile, O_WRONLY | O_CREAT, 0666);
	if (r[i][1] == -1)
		errorandstop(wfile);
	return (r);
}

int	main(int argc, t_string *argv)
{
	t_pipe		*pipes;
	int			i;
	const int	size_pipes = argc - 2;
	const int	nb_subprocess = argc - 3;

	startprogram();
	if (argc < 5)
	{
		print_str(err, 2, argv[0]);
		print_line(err, 2, ": takes at least 4 arguments.");
		endprogram(1);
	}
	pipes = create_pipes(size_pipes, argv[1], argv[argc - 1]);
	i = -1;
	while (++i < nb_subprocess)
		execcommand(pipes[i][0], pipes[i + 1][1], argv[i + 2]);
	while (wait(NULL) != -1)
		;
	if (errno != ECHILD)
		errorandstop("pipex");
	endprogram(0);
}
