/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 16:44:32 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:53 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_malloced(char *str1, char *str2)
{
	char		*res;
	size_t		len;
	size_t		len2;

	len = (str1) ? ft_strlen(str1) : 0;
	len2 = ft_strlen(str2);
	res = ft_strnew(len + len2);
	if (len)
	{
		ft_strncpy(res, str1, len);
		free(str1);
	}
	ft_strncpy(res + len, str2, len2);
	free(str2);
	return (res);
}

char		*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		len1;
	int		len2;

	len1 = (str1) ? ft_strlen(str1) : 0;
	len2 = (str2) ? ft_strlen(str2) : 0;
	res = ft_strnew(len1 + len2);
	ft_strncpy(res, str1, len1);
	ft_strncpy(res + len1, str2, len2);
	return (res);
}
