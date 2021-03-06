/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 12:36:45 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:59 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void **ptr, size_t size, size_t new_size)
{
	void	*mem;

	if (size == new_size)
		return (*ptr);
	mem = ft_memalloc(new_size);
	if (ptr == NULL)
		return (mem);
	if (mem)
	{
		ft_memcpy(mem, *ptr, size);
		ft_memdel(ptr);
	}
	return (mem);
}
