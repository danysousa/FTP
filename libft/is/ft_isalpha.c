/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:21:39 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:06 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL			ft_islower(int c)
{
	return ((c >= 'a') && (c <= 'z'));
}

BOOL			ft_isupper(int c)
{
	return ((c >= 'A') && (c <= 'Z'));
}

BOOL			ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
