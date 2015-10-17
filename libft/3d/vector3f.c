/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 12:24:50 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:15 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

VEC3	*new_vector3f(float x, float y, float z)
{
	VEC3	*vec;

	if ((vec = (VEC3 *)ft_memalloc(sizeof(VEC3))) == NULL)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

float	length3(VEC3 *vec)
{
	return ((float)sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

float	dot3(VEC3 *vec1, VEC3 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

VEC3	*cross3(VEC3 *vec1, VEC3 *vec2)
{
	float	x_;
	float	y_;
	float	z_;

	x_ = vec1->y * vec2->z - vec1->z * vec2->y;
	y_ = vec1->z * vec2->x - vec1->x * vec2->z;
	z_ = vec1->x * vec2->y - vec1->y * vec2->x;
	vec1->x = x_;
	vec1->y = y_;
	vec1->z = z_;
	return (vec1);
}

VEC3	*normalized3(VEC3 *vec)
{
	float	length;

	length = length3(vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
	return (vec);
}
