/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 11:25:17 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:49 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, size_t start, size_t len)
{
	size_t			i;
	char			*str;

	i = 0;
	str = ft_strnew(len);
	if (!str || !s)
		return (0);
	while (i++ < len)
		str[i - 1] = s[start++];
	return (str);
}
