/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 15:36:16 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:57:48 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static void		ft_trunc2(char msg, char **res, va_list ap)
{
	if (msg == '%')
		add_char(res, va_arg(ap, int));
	else if (msg == 'c')
		add_char(res, va_arg(ap, int));
	else if (msg == 's')
		add_str(res, va_arg(ap, char *));
	else if (msg == 'd' || msg == 'i')
		add_int(res, va_arg(ap, int));
	else if (msg == 'p')
		add_pattern(res, va_arg(ap, t_pattern));
}

char			*ft_trunc(const char *msg, ...)
{
	va_list		ap;
	char		*res;

	res = NULL;
	va_start(ap, msg);
	while (*msg)
	{
		if (*msg == '%')
		{
			msg++;
			ft_trunc2(*msg, &res, ap);
		}
		else
			add_char(&res, *msg);
		msg++;
	}
	va_end(ap);
	return (res);
}
