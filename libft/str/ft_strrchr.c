/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 11:20:39 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:50 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			search;

	search = (char)c;
	i = ft_strlen(s) - 1;
	if (search == '\0')
		return (i + 1 + (char*)s);
	while (i >= 0)
	{
		if (s[i] == search)
			return (i + (char*)s);
		i--;
	}
	return (NULL);
}
