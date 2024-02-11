/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:41:27 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:14:43 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	cylinder_height_normal(t_vector axis, t_vector rc, float norm)
{
	t_vector	normal;

	normal.x = rc.x - norm * axis.x;
	normal.y = rc.y - norm * axis.y;
	normal.z = rc.z - norm * axis.z;
	return (normal);
}

static t_vector	cylinder_disc_normal(t_vector axis, t_vector rc)
{
	t_vector	normal;

	if (vector_scalar_product(rc, axis) >= 0)
	{
		normal.x = axis.x;
		normal.y = axis.y;
		normal.z = axis.z;
	}
	else
	{
		normal.x = -axis.x;
		normal.y = -axis.y;
		normal.z = -axis.z;
	}
	return (normal);
}

t_vector	cylinder_normal(t_cylinder *cylinder, t_vector intersection)
{
	t_vector	normal;
	float		norm;
	float		axis_projection_norm;
	t_vector	rc;

	rc.x = intersection.x - cylinder->coordinate->x;
	rc.y = intersection.y - cylinder->coordinate->y;
	rc.z = intersection.z - cylinder->coordinate->z;
	axis_projection_norm = vector_scalar_product(rc, *cylinder->axis);
	if (fabsf(fabsf(axis_projection_norm) - cylinder->height / 2) < PRECISION)
		normal = cylinder_disc_normal(*cylinder->axis, rc);
	else
		normal = cylinder_height_normal(*cylinder->axis, rc, \
		axis_projection_norm);
	norm = vector_norm(normal);
	normal.x /= norm;
	normal.y /= norm;
	normal.z /= norm;
	return (normal);
}
