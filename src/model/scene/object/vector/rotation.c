/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:03:45 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/26 15:10:50 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	vector_sin(t_vector v1, t_vector v2)
{
	return (vector_norm(vector_cross_product(v1, v2)) / (vector_norm(v1) * vector_norm(v2)));
}

float	vector_cos(t_vector v1, t_vector v2)
{
	return (vector_scalar_product(v1, v2) / (vector_norm(v1) * vector_norm(v2)));
}

//axis: axis of the rotation
//c: cosinus of the angle
//s: sinus of the angle
t_vector	vector_rotation_cs(t_vector v, t_vector axis, float c, float s)
{
	return ((t_vector){(axis.x * axis.x * (1 - c) + c) * v.x + \
	(axis.x * axis.y * (1 - c) - axis.z * s) * v.y + \
	(axis.x * axis.z * (1 - c) + axis.y * s) * v.z, \
	(axis.x * axis.y * (1 - c) + axis.z * s) * v.x + \
	(axis.y * axis.y * (1 - c) + c) * v.y + \
	(axis.y * axis.z * (1 - c) - axis.x * s) * v.z, \
	(axis.x * axis.z * (1 - c) - axis.y * s) * v.x + \
	(axis.y * axis.z * (1 - c) + axis.x * s) * v.y + \
	(axis.z * axis.z * (1 - c) + c) * v.z});
}

void	base_rotate(t_vector base[3], t_vector direction)
{
	t_vector	axis;
	float		c;
	float		s;

	axis = vector_cross_product(direction, base[2]);
	c = vector_cos(direction, base[2]);
	s = vector_sin(direction, base[2]);
	base[0] = vector_rotation_cs(base[0], axis, c, s);
	base[1] = vector_rotation_cs(base[1], axis, c, s);
	base[2] = vector_rotation_cs(base[2], axis, c, s);
}