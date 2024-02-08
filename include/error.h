/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:30:36 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/21 16:09:30 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libtf.h"

void		err(t_const_string msg);
t_memclass	get_mc(void);
void		startprogram(void);
void		errorandstop(t_const_string what);
void		endprogram(int no);

#endif
