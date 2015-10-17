/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 12:47:08 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:57 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, size_t base)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if ((size_t)n >= base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'A');
	}
}

void	ft_putnbr_base_fd(int n, size_t base, size_t fd)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if ((size_t)n >= base)
	{
		ft_putnbr_base_fd(n / base, base, fd);
		ft_putnbr_base_fd(n % base, base, fd);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		else
			ft_putchar_fd(n - 10 + 'A', fd);
	}
}
