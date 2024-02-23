/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:30:26 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/23 16:49:42 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "libtf.h"
#include "error.h"

static t_const_string	pop_argv0(t_const_string new)
{
	static t_const_string	value = NULL;
	t_const_string			r;

	r = value;
	value = new;
	return (r);
}

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

void	err(t_const_string msg)
{
	(void)msg;
	if (!errno)
		errno = 1;
	errorandstop(pop_argv0(NULL));
}

void	startprogram(t_const_string argv0)
{
	pop_argv0(argv0);
	pop_mc(mem_newclass(err));
}
