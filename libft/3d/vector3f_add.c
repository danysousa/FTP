/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:29:18 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 13:58:14 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

VEC3	*add3f(VEC3 *vec1, float value)
{
	vec1->x += value;
	vec1->y += value;
	vec1->z += value;
	return (vec1);
}

VEC3	*add3v(VEC3 *vec1, VEC3 *vec2)
{
	vec1->x += vec2->x;
	vec1->y += vec2->y;
	vec1->z += vec2->z;
	return (vec1);
}
