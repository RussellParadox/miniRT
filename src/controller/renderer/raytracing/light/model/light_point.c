/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 03:58:34 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 03:02:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	diffuse_weight(t_vector *l, t_vector *normal)
{
	float	weight;

	weight = vector_scalar_product(l, normal);
	if (weight < PRECISION)
		return (0);
	return (weight / vector_norm(l));
}

static float	specular_weight(t_vector *l, t_vector *normal, t_camera *camera, float specular)
{
	float		weight;
	t_vector	ic;
	t_vector	reflection;

	ic.x = -camera->orientation->x;
	ic.y = -camera->orientation->y;
	ic.z = -camera->orientation->z;
	weight = vector_scalar_product(l, normal);
	reflection.x = 2 * weight * normal->x - l->x;
	reflection.y = 2 * weight * normal->y - l->y;
	reflection.z = 2 * weight * normal->z - l->z;
	weight = vector_scalar_product(&ic, &reflection);
	if (weight > 0)
		return (powf(weight / (vector_norm(&reflection) * vector_norm(&ic)), specular));
	return (0);
}

void	light_point_model(t_vector *intensity, t_light *light, float specular, void *arg[4])
{
	t_vector	l;
	float		weight;
	t_vector	*normal;
	t_vector	*intersection;

	intersection = arg[0];
	normal = arg[2];
	l.x = light->coordinate->x - intersection->x;
	l.y = light->coordinate->y - intersection->y;
	l.z = light->coordinate->z - intersection->z;
	if (shadow_model(arg[3], intersection, &l))
		return ;
	weight = diffuse_weight(&l, normal);
	if (!(specular < 0))
		weight += specular_weight(&l, normal, (t_camera *)(arg[1]), specular);
	weight *= light->ratio;
	intensity->x += weight * light->color->red / light->color->sum;
	intensity->y += weight * light->color->green / light->color->sum;
	intensity->z += weight * light->color->blue / light->color->sum;
}