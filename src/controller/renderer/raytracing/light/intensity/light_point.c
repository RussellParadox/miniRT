/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 03:58:34 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:33:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	diffuse_intensity(t_vector l, t_vector normal)
{
	float	l_dot_n;

	l_dot_n = vector_scalar_product(l, normal);
	if (l_dot_n < PRECISION)
		return (0);
	return (l_dot_n / vector_norm(l));
}

static float	specular_intensity(t_vector l, t_vector normal, \
t_vector v, float s)
{
	t_vector	r;
	float		r_dot_v;

	if (s < PRECISION)
		return (0);
	r = reflection(normal, l);
	r_dot_v = vector_scalar_product(r, v);
	if (r_dot_v > 0)
		return (powf(r_dot_v / (vector_norm(r) * vector_norm(v)), s));
	return (0);
}

t_vector	light_point_intensity(t_light *light, t_vector normal, \
t_vector v, t_vector l)
{
	t_vector	intensity;
	float		weight;
	float		s;

	s = *(float *)capsule(NULL);
	weight = light->ratio * (diffuse_intensity(l, normal) \
	+ specular_intensity(l, normal, v, s));
	intensity.x = weight * light->color->red / light->color->sum;
	intensity.y = weight * light->color->green / light->color->sum;
	intensity.z = weight * light->color->blue / light->color->sum;
	return (intensity);
}
