/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execfrompath.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:01:37 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/22 15:39:43 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECFROMPATH_H
# define EXECFROMPATH_H

# include "libtf.h"

/**
 * Call the program. If it isn't a path (no '/'), try to find it in $PATH.
 * Doesn't return.
 */
void	execfrompath(t_string argv[], t_const_string envp[]);

#endif
