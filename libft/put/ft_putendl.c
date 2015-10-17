/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 14:51:21 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:58 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
}

void	ft_putendl_fd(char *str, size_t fd)
{
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}
