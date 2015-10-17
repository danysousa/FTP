/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:20:02 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:25 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

MAT4		*to_rotation_matrix(QUAT *q)
{
	MAT4	*mat;

	q = normalized4(q);
	mat = new_matrix4();
	mat->m[0][0] = 1.0f - 2.0f * q->y * q->y - 2.0f * q->z * q->z;
	mat->m[0][1] = 2.0f * q->x * q->y - 2.0f * q->z * q->w;
	mat->m[0][2] = 2.0f * q->x * q->z + 2.0f * q->y * q->w;
	mat->m[0][3] = 0.0f;
	mat->m[1][0] = 2.0f * q->x * q->y + 2.0f * q->z * q->w;
	mat->m[1][1] = 1.0f - 2.0f * q->x * q->x - 2.0f * q->z * q->z;
	mat->m[1][2] = 2.0f * q->y * q->z - 2.0f * q->x * q->w;
	mat->m[1][3] = 0.0f;
	mat->m[2][0] = 2.0f * q->x * q->z - 2.0f * q->y * q->w;
	mat->m[2][1] = 2.0f * q->y * q->z + 2.0f * q->x * q->w;
	mat->m[2][2] = 1.0f - 2.0f * q->x * q->x - 2.0f * q->y * q->y;
	mat->m[2][3] = 0.0f;
	mat->m[3][0] = 0.0f;
	mat->m[3][1] = 0.0f;
	mat->m[3][2] = 0.0f;
	mat->m[3][3] = 1.0f;
	return (mat);
}
