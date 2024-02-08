/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcommand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:19:06 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/21 14:55:58 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtf.h"
#include "error.h"
#include "execsubprocess.h"

void	execcommand(int readfd, int writefd, const char *command)
{
	t_string	*argv;

	argv = str_split(err, get_mc(), command, " \t\n");
	execsubprocess(readfd, writefd, argv);
}
