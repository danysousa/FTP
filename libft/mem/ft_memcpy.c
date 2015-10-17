/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 12:39:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:00 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	*dp;
	size_t	*sp;

	if (n <= 0)
		return (dest);
	dp = (size_t *)dest;
	sp = (size_t *)src;
	while (n--)
		*dp++ = *sp++;
	return (dest);
}
