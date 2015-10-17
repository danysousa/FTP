/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:19:46 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:12 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

VEC3	*rotate3(VEC3 *vec, VEC3 *axis, float angle)
{
	float		sin_angle;
	float		cos_angle;

	sin_angle = (float)sin(-angle);
	cos_angle = (float)cos(-angle);
	vec = cross3(vec, mul3f(axis, sin_angle));
	vec = add3v(vec, mul3f(vec, cos_angle));
	vec = add3v(vec, mul3f(vec, dot3(vec, mul3f(axis, 1 - cos_angle))));
	return (vec);
}

VEC3	*rotate3q(VEC3 *vec, QUAT *rotation)
{
	QUAT	conjugate;
	QUAT	w;

	w.x = rotation->x;
	w.y = rotation->y;
	w.z = rotation->z;
	w.w = rotation->w;
	conjugate.x = -rotation->x;
	conjugate.y = -rotation->y;
	conjugate.z = -rotation->z;
	conjugate.w = rotation->w;
	w = *mul4q(mul4v(&w, vec), &conjugate);
	vec->x = w.x;
	vec->y = w.y;
	vec->z = w.z;
	return (vec);
}
