/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:30:36 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/23 16:46:17 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libtf.h"

void		err_commandnotfound(t_const_string what);

void		err(t_const_string msg);
t_memclass	get_mc(void);
void		startprogram(t_const_string argv0);
void		errorandstop(t_const_string what);
void		endprogram(int no);

#endif
