/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:05:39 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:25 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

TRAN		*new_transform(void)
{
	TRAN		*t;

	if ((t = (TRAN *)ft_memalloc(sizeof(TRAN))) == NULL)
		return (NULL);
	t->pos.x = 0;
	t->pos.y = 0;
	t->pos.z = 0;
	t->rot.x = 0;
	t->rot.y = 0;
	t->rot.z = 0;
	t->rot.w = 1;
	t->scale.x = 1;
	t->scale.y = 1;
	t->scale.z = 1;
	return (t);
}

VEC3		*transform(VEC3 *v, MAT4 *m)
{
	VEC3	*res;
	float	x;
	float	y;
	float	z;

	if ((res = (VEC3 *)ft_memalloc(sizeof(VEC3))) == NULL)
		return (NULL);
	x = m->m[0][0] * v->x + m->m[0][1] * v->y + m->m[0][2] * v->z + m->m[0][3];
	y = m->m[1][0] * v->x + m->m[1][1] * v->y + m->m[1][2] * v->z + m->m[1][3];
	z = m->m[2][0] * v->x + m->m[2][1] * v->y + m->m[2][2] * v->z + m->m[2][3];
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}

MAT4		*get_transforms(TRAN *t)
{
	MAT4	*translation;
	MAT4	*rotation;
	MAT4	*scale;
	MAT4	*tmp;
	MAT4	*tmp2;

	translation = init_translation(&t->pos);
	rotation = to_rotation_matrix(&t->rot);
	scale = init_scale(t->scale.x, t->scale.y, t->scale.z);
	tmp = mul4m(translation, rotation);
	ft_memdel((void **)&rotation);
	ft_memdel((void **)&translation);
	tmp2 = mul4m(tmp, scale);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&scale);
	return (tmp2);
}
