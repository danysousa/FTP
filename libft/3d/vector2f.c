/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 12:24:33 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:23 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

VEC2	*new_vector2f(float x, float y)
{
	VEC2 *vec;

	if ((vec = (VEC2 *)ft_memalloc(sizeof(VEC2))) == NULL)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}

float	length2(VEC2 *vec)
{
	return ((float)sqrt(vec->x * vec->x + vec->y * vec->y));
}

float	dot2(VEC2 *vec1, VEC2 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y);
}

float	cross2(VEC2 *vec1, VEC2 *vec2)
{
	return (vec1->x * vec2->y - vec1->y * vec2->x);
}

VEC2	*normalized2(VEC2 *vec)
{
	float	length;

	length = length2(vec);
	vec->x /= length;
	vec->y /= length;
	return (vec);
}
