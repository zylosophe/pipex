/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:36:49 by mcolonna          #+#    #+#             */
/*   Updated: 2024/01/23 18:16:18 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_utils.h"

void	*create_address_with_element(t_element *element, size_t size)
{
	void	*r;

	r = malloc(sizeof(t_element *) + size);
	if (!r)
		return (free(r), NULL);
	*((t_element **)r) = element;
	return ((void *)((char *)r + sizeof(t_element *)));
}

t_element	*get_address_element(void *address)
{
	return (*(t_element **)((char *)address - sizeof(t_element *)));
}

void	free_address_with_element(void *address)
{
	free((char *)address - sizeof(t_element *));
}
