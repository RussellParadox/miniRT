/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:41:27 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/17 07:49:45 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	height_normal(t_vector *normal, t_cylinder *cylinder, t_vector *rc, float norm)
{
	norm /= vector_norm(cylinder->axis);
	normal->x = rc->x - norm * cylinder->axis->x;
	normal->y = rc->y - norm * cylinder->axis->y;
	normal->z = rc->z - norm * cylinder->axis->z;
}

static void	disc_normal(t_vector *normal, t_cylinder *cylinder, t_vector *rc)
{
	if (vector_scalar_product(rc, cylinder->axis) >= 0)
	{
		normal->x = cylinder->axis->x;
		normal->y = cylinder->axis->y;
		normal->z = cylinder->axis->z;
	}
	else
	{
		normal->x = -cylinder->axis->x;
		normal->y = -cylinder->axis->y;
		normal->z = -cylinder->axis->z;
	}
}

void	cylinder_normal(t_vector *normal, t_cylinder *cylinder, t_vector *intersection)
{
	float		norm;
	float		axis_projection_norm;
	t_vector	rc;

	rc.x = intersection->x - cylinder->coordinate->x;
	rc.y = intersection->y - cylinder->coordinate->y;
	rc.z = intersection->z - cylinder->coordinate->z;
	axis_projection_norm = vector_scalar_product(&rc, cylinder->axis) / vector_norm(cylinder->axis);
	if (fabsf(fabsf(axis_projection_norm) - cylinder->height / 2) < PRECISION)
		disc_normal(normal, cylinder, &rc);
	else
		height_normal(normal, cylinder, &rc, axis_projection_norm);
	norm = vector_norm(normal);
	normal->x /= norm;
	normal->y /= norm;
	normal->z /= norm;
}