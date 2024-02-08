/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:30:26 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/21 16:06:29 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "libtf.h"
#include "error.h"

static t_memclass	pop_mc(t_memclass new)
{
	static t_memclass	value = NULL;
	t_memclass			r;

	r = value;
	value = new;
	return (r);
}

t_memclass	get_mc(void)
{
	t_memclass	r;

	r = pop_mc(NULL);
	pop_mc(r);
	return (r);
}

void	errorandstop(const char *what)
{
	perror(what);
	endprogram(errno);
}

void	startprogram(void)
{
	pop_mc(mem_newclass(err));
}

void	endprogram(int no)
{
	t_memclass	mc;

	mc = pop_mc(NULL);
	if (mc)
		mem_freeall(mc);
	exit(no);
}
