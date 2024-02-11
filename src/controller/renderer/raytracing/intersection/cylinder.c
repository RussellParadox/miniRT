/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:05:19 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 09:11:19 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	height_length(t_ray ray, t_cylinder *cylinder, float parameter)
{
	t_vector	rc;

	rc.x = ray.origin.x + parameter * ray.direction.x - cylinder->coordinate->x;
	rc.y = ray.origin.y + parameter * ray.direction.y - cylinder->coordinate->y;
	rc.z = ray.origin.z + parameter * ray.direction.z - cylinder->coordinate->z;
	return (2 * fabsf(vector_scalar_product(rc, *cylinder->axis)));
}

static float	disc_diameter(t_ray ray, t_cylinder *cylinder, float parameter)
{
	t_vector	p;
	t_vector	rc;
	float		s1;
	float		s2;

	rc.x = ray.origin.x + parameter * ray.direction.x - cylinder->coordinate->x;
	rc.y = ray.origin.y + parameter * ray.direction.y - cylinder->coordinate->y;
	rc.z = ray.origin.z + parameter * ray.direction.z - cylinder->coordinate->z;
	s1 = vector_scalar_product(rc, *cylinder->axis);
	s2 = vector_scalar_product(*cylinder->axis, *cylinder->axis);
	p.x = rc.x - (s1 * cylinder->axis->x) / s2;
	p.y = rc.y - (s1 * cylinder->axis->y) / s2;
	p.z = rc.z - (s1 * cylinder->axis->z) / s2;
	return (2 * vector_norm(p));
}

static float	height_intersection(t_ray ray, \
t_cylinder *cylinder, t_vector oc)
{
	float		parameter;
	t_vector	v;
	t_vector	u;
	float		s1;
	float		s2;

	s1 = vector_scalar_product(oc, *cylinder->axis);
	s2 = vector_scalar_product(*cylinder->axis, *cylinder->axis);
	v.x = oc.x - (s1 * cylinder->axis->x) / s2;
	v.y = oc.y - (s1 * cylinder->axis->y) / s2;
	v.z = oc.z - (s1 * cylinder->axis->z) / s2;
	s1 = vector_scalar_product(ray.direction, *cylinder->axis);
	u.x = ray.direction.x - (s1 * cylinder->axis->x) / s2;
	u.y = ray.direction.y - (s1 * cylinder->axis->y) / s2;
	u.z = ray.direction.z - (s1 * cylinder->axis->z) / s2;
	parameter = intersection_quadratic_minimum(vector_scalar_product(u, u), \
	2 * vector_scalar_product(v, u), vector_scalar_product(v, v) - \
	powf(cylinder->diameter, 2) / 4, ray.parameter_min);
	if (height_length(ray, cylinder, parameter) > cylinder->height)
		return (FLT_MAX);
	return (parameter);
}

static float	disc_intersection(t_ray ray, t_cylinder *cylinder, t_vector oc)
{
	float	parameter1;
	float	parameter2;
	float	directions_product;

	directions_product = vector_scalar_product(ray.direction, *cylinder->axis);
	if (fabsf(directions_product) < PRECISION)
		return (FLT_MAX);
	parameter1 = (cylinder->height - 2 * vector_scalar_product(oc, \
	*cylinder->axis)) / (2 * directions_product);
	if (disc_diameter(ray, cylinder, parameter1) > cylinder->diameter)
		parameter1 = FLT_MAX;
	parameter2 = (-cylinder->height - 2 * vector_scalar_product(oc, \
	*cylinder->axis)) / (2 * directions_product);
	if (disc_diameter(ray, cylinder, parameter2) > cylinder->diameter)
		parameter2 = FLT_MAX;
	if (parameter1 < parameter2 && parameter1 > ray.parameter_min)
		return (parameter1);
	else if (parameter2 > ray.parameter_min)
		return (parameter2);
	return (FLT_MAX);
}

float	ray_cylinder_intersection(t_ray ray, t_cylinder *cylinder)
{
	float		parameter1;
	float		parameter2;
	t_vector	oc;

	oc.x = ray.origin.x - cylinder->coordinate->x;
	oc.y = ray.origin.y - cylinder->coordinate->y;
	oc.z = ray.origin.z - cylinder->coordinate->z;
	parameter1 = disc_intersection(ray, cylinder, oc);
	parameter2 = height_intersection(ray, cylinder, oc);
	if (parameter1 < parameter2 && parameter1 > ray.parameter_min)
		return (parameter1);
	else if (parameter2 > ray.parameter_min)
		return (parameter2);
	return (FLT_MAX);
}
