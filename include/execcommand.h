/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcommand.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:15:46 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/22 15:40:04 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECCOMMAND_H
# define EXECCOMMAND_H

/**
 * Execute a command from a string.
 * Split each argument at spaces.
 * - readfd: will be use for the stdin.
 * - writefd: will be use for the stdout.
 * - command: command string
 */
void	execcommand(
			int readfd, int writefd, t_const_string command,
			t_const_string envp[]);

#endif
