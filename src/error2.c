/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:55 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/23 16:47:36 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "libtf.h"
#include "error.h"

void	err_commandnotfound(t_const_string what)
{
	print_line(err, 2, str_join(err, get_mc(), what, ": command not found"));
	endprogram(127);
}

void	errorandstop(t_const_string what)
{
	perror(what);
	endprogram(errno);
}

void	endprogram(int no)
{
	t_memclass	mc;

	mc = get_mc();
	if (mc)
		mem_freeall(mc);
	exit(no);
}
