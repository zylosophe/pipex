/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcommand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:19:06 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/22 15:21:09 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtf.h"
#include "error.h"
#include "execsubprocess.h"

void	execcommand(
	int readfd, int writefd, t_const_string command, t_const_string envp[])
{
	t_string	*argv;

	argv = str_split(err, get_mc(), command, " \t\n");
	execsubprocess(readfd, writefd, argv, envp);
}
