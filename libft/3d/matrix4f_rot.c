/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4f_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:22:59 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:26 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static MAT4		init_rotation_x(float x)
{
	MAT4	rx;

	rx.m[0][0] = 1;
	rx.m[0][1] = 0;
	rx.m[0][2] = 0;
	rx.m[0][3] = 0;
	rx.m[1][0] = 0;
	rx.m[1][1] = (float)cos(x);
	rx.m[1][2] = -(float)sin(x);
	rx.m[1][3] = 0;
	rx.m[2][0] = 0;
	rx.m[2][1] = (float)sin(x);
	rx.m[2][2] = (float)cos(x);
	rx.m[2][3] = 0;
	rx.m[3][0] = 0;
	rx.m[3][1] = 0;
	rx.m[3][2] = 0;
	rx.m[3][3] = 1;
	return (rx);
}

static MAT4		init_rotation_y(float y)
{
	MAT4	ry;

	ry.m[0][0] = (float)cos(y);
	ry.m[0][1] = 0;
	ry.m[0][2] = -(float)sin(y);
	ry.m[0][3] = 0;
	ry.m[1][0] = 0;
	ry.m[1][1] = 1;
	ry.m[1][2] = 0;
	ry.m[1][3] = 0;
	ry.m[2][0] = (float)sin(y);
	ry.m[2][1] = 0;
	ry.m[2][2] = (float)cos(y);
	ry.m[2][3] = 0;
	ry.m[3][0] = 0;
	ry.m[3][1] = 0;
	ry.m[3][2] = 0;
	ry.m[3][3] = 1;
	return (ry);
}

static MAT4		init_rotation_z(float z)
{
	MAT4	rz;

	rz.m[0][0] = (float)cos(z);
	rz.m[0][1] = -(float)sin(z);
	rz.m[0][2] = 0;
	rz.m[0][3] = 0;
	rz.m[1][0] = (float)sin(z);
	rz.m[1][1] = (float)cos(z);
	rz.m[1][2] = 0;
	rz.m[1][3] = 0;
	rz.m[2][0] = 0;
	rz.m[2][1] = 0;
	rz.m[2][2] = 1;
	rz.m[2][3] = 0;
	rz.m[3][0] = 0;
	rz.m[3][1] = 0;
	rz.m[3][2] = 0;
	rz.m[3][3] = 1;
	return (rz);
}

MAT4			*init_rotation3f(float x, float y, float z)
{
	MAT4	rx;
	MAT4	ry;
	MAT4	rz;
	MAT4	*res;

	if ((res = (MAT4 *)ft_memalloc(sizeof(MAT4))) == NULL)
		return (NULL);
	x = to_radians(x);
	y = to_radians(y);
	z = to_radians(z);
	rx = init_rotation_x(x);
	ry = init_rotation_y(y);
	rz = init_rotation_z(z);
	res = mul4m(&rz, mul4m(&ry, &rx));
	return (res);
}

MAT4			*init_rotation3v(VEC3 *f, VEC3 *u, VEC3 *r)
{
	MAT4	*m;

	if ((m = (MAT4 *)ft_memalloc(sizeof(MAT4))) == NULL)
		return (NULL);
	m->m[0][0] = r->x;
	m->m[0][1] = r->y;
	m->m[0][2] = r->z;
	m->m[0][3] = 0;
	m->m[1][0] = u->x;
	m->m[1][1] = u->y;
	m->m[1][2] = u->z;
	m->m[1][3] = 0;
	m->m[2][0] = f->x;
	m->m[2][1] = f->y;
	m->m[2][2] = f->z;
	m->m[2][3] = 0;
	m->m[3][0] = 0;
	m->m[3][1] = 0;
	m->m[3][2] = 0;
	m->m[3][3] = 1;
	return (m);
}
