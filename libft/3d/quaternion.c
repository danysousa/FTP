/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 13:09:33 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:26 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

QUAT	*new_quaternion4f(float x, float y, float z, float w)
{
	QUAT	*q;

	if ((q = (QUAT *)ft_memalloc(sizeof(QUAT))) == NULL)
		return (NULL);
	q->x = x;
	q->y = y;
	q->z = z;
	q->w = w;
	return (q);
}

QUAT	*new_quaternion4vf(VEC3 *axis, float angle)
{
	QUAT			*q;
	float			sin_half_angle;
	float			cos_half_angle;

	if ((q = (QUAT *)ft_memalloc(sizeof(QUAT))) == NULL)
		return (NULL);
	sin_half_angle = sinf(to_radians(angle) / 2);
	cos_half_angle = cosf(to_radians(angle) / 2);
	q->x = axis->x * sin_half_angle;
	q->y = axis->y * sin_half_angle;
	q->z = axis->z * sin_half_angle;
	q->w = cos_half_angle;
	return (q);
}

float	length4(QUAT *q)
{
	return ((float)sqrt(q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w));
}

QUAT	*normalized4(QUAT *q)
{
	float	l;

	l = length4(q);
	q->x /= l;
	q->y /= l;
	q->z /= l;
	q->w /= l;
	return (q);
}

QUAT	*conjugate4(QUAT *q)
{
	q->x = -q->x;
	q->y = -q->y;
	q->z = -q->z;
	return (q);
}
