/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 12:01:51 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:24 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		to_radians(float angle)
{
	return (angle * M_PI / 180);
}

float		rt(float val)
{
	return (val * val);
}
