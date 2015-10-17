/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 12:48:53 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:57 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(void *adr)
{
	write(1, "0x", 2);
	ft_putnbr_base((size_t)adr, 16);
}

void	ft_putmem_fd(void *adr, size_t fd)
{
	write(fd, "0x", 2);
	ft_putnbr_base_fd((size_t)adr, 16, fd);
}
