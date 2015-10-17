/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 17:17:01 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:54 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	res = ft_strnew(len);
	ft_strncpy(res, str, len);
	return (res);
}
