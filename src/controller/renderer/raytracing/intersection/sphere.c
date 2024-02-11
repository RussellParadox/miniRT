/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:50:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ray_sphere_intersection(t_ray ray, t_sphere *sphere)
{
	t_vector	oc;

	oc.x = ray.origin.x - sphere->coordinate->x;
	oc.y = ray.origin.y - sphere->coordinate->y;
	oc.z = ray.origin.z - sphere->coordinate->z;
	return (intersection_quadratic_minimum(\
	vector_scalar_product(ray.direction, ray.direction), \
	2 * vector_scalar_product(oc, ray.direction), \
	vector_scalar_product(oc, oc) - powf(sphere->diameter / 2, 2), \
	ray.parameter_min));
}
