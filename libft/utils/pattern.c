/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:56:13 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:41 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static char		*trunc_2(const char *msg, va_list ap)
{
	char		*res;

	res = NULL;
	while (*msg)
	{
		if (*msg == '%')
		{
			msg++;
			if (*msg == '%')
				add_char(&res, va_arg(ap, int));
			else if (*msg == 'c')
				add_char(&res, va_arg(ap, int));
			else if (*msg == 's')
				add_str(&res, va_arg(ap, char *));
			else if (*msg == 'd' || *msg == 'i')
				add_int(&res, va_arg(ap, int));
			else if (*msg == 'p')
				add_pattern(&res, va_arg(ap, t_pattern));
		}
		else
			add_char(&res, *msg);
		msg++;
	}
	return (res);
}

t_pattern		pattern(int repeat, const char *msg, ...)
{
	t_pattern	pattern;
	char		*tmp;
	char		*tmp2;
	int			i;
	va_list		ap;

	i = 0;
	va_start(ap, msg);
	pattern.str = trunc_2(msg, ap);
	va_end(ap);
	tmp = ft_strdup(pattern.str);
	while (i < repeat - 1)
	{
		tmp2 = tmp;
		tmp = ft_strjoin(tmp2, pattern.str);
		free(tmp2);
		i++;
	}
	pattern.str = tmp;
	return (pattern);
}
