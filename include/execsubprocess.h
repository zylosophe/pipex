/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execsubprocess.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:06:13 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/21 14:02:47 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECSUBPROCESS_H
# define EXECSUBPROCESS_H

/**
 * Execute a command and intercept its stdin and stdout.
 * - readfd: will be use for the stdin.
 * - writefd: will be use for the stdout.
 * - args: list of arguments ended by NULL. args[0] is the program.
 */
void	execsubprocess(int readfd, int writefd, char **argv);

#endif
