/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/12 20:05:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ray_sphere_intersection(t_ray *ray, t_sphere *sphere)
{
	t_vector	oc;
	float		delta;
	float		parameter1;
	float		parameter2;
	float		a;
	float		b;
	float		c;

	oc.x = ray->origin->x - sphere->coordinate->x;
	oc.y = ray->origin->y - sphere->coordinate->y;
	oc.z = ray->origin->z - sphere->coordinate->z;
	a = vector_scalar_product(ray->direction, ray->direction);
	b = 2 * vector_scalar_product(&oc, ray->direction);
	c = vector_scalar_product(&oc, &oc) - powf(sphere->diameter / 2, 2);
	delta = powf(b, 2) - 4 * a * c;
	if (delta < 0)
		return (FLT_MAX);
	else
	{
		parameter1 = (-b - sqrtf(delta)) / (2 * a);
		parameter2 = (-b + sqrtf(delta)) / (2 * a);
		if (parameter1 < parameter2)
			return (parameter1);
		else
			return (parameter2);
	}
}