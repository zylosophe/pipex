/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:08:16 by mcolonna          #+#    #+#             */
/*   Updated: 2024/02/23 13:27:46 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtf.h"
#include "mem_utils.h"
#include <stdlib.h>

t_memclass	mem_newclass(t_err *err)
{
	t_memclass_in	r;

	r = malloc(sizeof(t_memclass_in));
	if (!r)
		return ((*err)("alloc error"), NULL);
	r->first = NULL;
	return (r);
}

void	*mem_alloc(t_err *err, t_memclass mc, size_t size)
{
	void			*r;
	t_element		*new_element;
	t_memclass_in	mc_in;

	mc_in = (t_memclass_in) mc;
	new_element = malloc(sizeof(t_element));
	if (!new_element)
		return ((*err)("alloc error"), NULL);
	r = create_address_with_element(new_element, size);
	if (!r)
		return ((*err)("alloc error"), NULL);
	new_element->address = r;
	new_element->next = mc_in->first;
	if (new_element->next)
		new_element->next->previous = new_element;
	new_element->previous = NULL;
	new_element->mc = mc;
	mc_in->first = new_element;
	return (r);
}

void	mem_freeall(t_memclass mc)
{
	t_element	*el;
	t_element	*next;

	if (!mc)
		return ;
	el = ((t_memclass_in) mc)->first;
	while (el)
	{
		next = el->next;
		free_address_with_element(el->address);
		free(el);
		el = next;
	}
	free(mc);
}

void	mem_free(void *address)
{
	t_element	*el;

	if (!address)
		return ;
	el = get_address_element(address);
	free_address_with_element(address);
	if (el->previous)
		el->previous->next = el->next;
	else
		el->mc->first = el->next;
	if (el->next)
		el->next->previous = el->previous;
	free(el);
}
