/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:33:26 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:50:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ray_plane_intersection(t_ray ray, t_plane *plane)
{
	float		directions_product;
	t_vector	oc;

	directions_product = vector_scalar_product(ray.direction, *plane->normal);
	if (fabsf(directions_product) < PRECISION)
		return (FLT_MAX);
	oc.x = plane->coordinate->x - ray.origin.x;
	oc.y = plane->coordinate->y - ray.origin.y;
	oc.z = plane->coordinate->z - ray.origin.z;
	return (vector_scalar_product(*plane->normal, oc) / directions_product);
}
