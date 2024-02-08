/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execcommand.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:15:46 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/21 14:02:36 by mcolonna         ###   ########.fr       */
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
void	execcommand(int readfd, int writefd, char *comman);

#endif
