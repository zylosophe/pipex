/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:55 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/21 16:10:41 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libtf.h"
#include "error.h"

void	err(t_const_string msg)
{
	(void)msg;
	if (!errno)
		errno = 1;
	errorandstop("pipex");
}
