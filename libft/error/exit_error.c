/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 15:04:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:08 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_error(char *error)
{
	ft_putstr_fd(ANSI_COLOR_RED, 2);
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(ANSI_COLOR_RESET, 2);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	exit(-42);
}
