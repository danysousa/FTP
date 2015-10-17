/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_trunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:57:44 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:43 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			add_char(char **res, char c)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_memalloc(2);
	tmp[0] = c;
	if (*res == NULL)
	{
		*res = tmp;
		return ;
	}
	tmp2 = *res;
	*res = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

void			add_str(char **res, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(str);
	if (*res == NULL)
	{
		*res = tmp;
		return ;
	}
	tmp2 = *res;
	*res = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

void			add_int(char **res, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_itoa(i);
	if (*res == NULL)
	{
		*res = tmp;
		return ;
	}
	tmp2 = *res;
	*res = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

void			add_pattern(char **res, t_pattern pat)
{
	add_str(res, pat.str);
	free(pat.str);
}
