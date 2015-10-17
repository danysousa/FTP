/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 15:19:24 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:27 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

MAT4		*new_matrix4(void)
{
	MAT4	*res;

	if ((res = (MAT4 *)ft_memalloc(sizeof(MAT4))) == NULL)
		return (NULL);
	res->m[0][0] = 1;
	res->m[0][1] = 0;
	res->m[0][2] = 0;
	res->m[0][3] = 0;
	res->m[1][0] = 0;
	res->m[1][1] = 1;
	res->m[1][2] = 0;
	res->m[1][3] = 0;
	res->m[2][0] = 0;
	res->m[2][1] = 0;
	res->m[2][2] = 1;
	res->m[2][3] = 0;
	res->m[3][0] = 0;
	res->m[3][1] = 0;
	res->m[3][2] = 0;
	res->m[3][3] = 1;
	return (res);
}

MAT4		*mul4m(MAT4 *m, MAT4 *r)
{
	MAT4		*res;
	int			i;
	int			j;

	if ((res = (MAT4 *)ft_memalloc(sizeof(MAT4))) == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res->m[i][j] = m->m[i][0] * r->m[0][j] + \
							m->m[i][1] * r->m[1][j] + \
							m->m[i][2] * r->m[2][j] + \
							m->m[i][3] * r->m[3][j];
			j++;
		}
		i++;
	}
	return (res);
}

MAT4		*init_translation(VEC3 *vec)
{
	MAT4	*m;

	if ((m = (MAT4 *)ft_memalloc(sizeof(MAT4))) == NULL)
		return (NULL);
	m->m[0][0] = 1;
	m->m[0][1] = 0;
	m->m[0][2] = 0;
	m->m[0][3] = 0;
	m->m[1][0] = 0;
	m->m[1][1] = 1;
	m->m[1][2] = 0;
	m->m[1][3] = 0;
	m->m[2][0] = 0;
	m->m[2][1] = 0;
	m->m[2][2] = 1;
	m->m[2][3] = 0;
	m->m[3][0] = vec->x;
	m->m[3][1] = vec->y;
	m->m[3][2] = vec->z;
	m->m[3][3] = 1;
	return (m);
}

MAT4		*init_scale(float x, float y, float z)
{
	MAT4	*m;

	if ((m = (MAT4 *)ft_memalloc(sizeof(MAT4))) == NULL)
		return (NULL);
	m->m[0][0] = x;
	m->m[0][1] = 0;
	m->m[0][2] = 0;
	m->m[0][3] = 0;
	m->m[1][0] = 0;
	m->m[1][1] = y;
	m->m[1][2] = 0;
	m->m[1][3] = 0;
	m->m[2][0] = 0;
	m->m[2][1] = 0;
	m->m[2][2] = z;
	m->m[2][3] = 0;
	m->m[3][0] = 0;
	m->m[3][1] = 0;
	m->m[3][2] = 0;
	m->m[3][3] = 1;
	return (m);
}
