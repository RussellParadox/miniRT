/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 03:37:14 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:31:51 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vector	intensity_max(float ratio, t_color color)
{
	if (ratio < 0)
		return ((t_vector){0, 0, 0});
	return ((t_vector){ratio * color.red / color.sum, \
	ratio * color.green / color.sum, \
	ratio * color.blue / color.sum});
}

void	init_intensity(t_vector *intensity, t_vector *max_sum, t_list *scene)
{
	t_ambient_lightning	*ambient_lightning;

	ambient_lightning = (t_ambient_lightning *)object_find("A", scene);
	*intensity = ambient_lightning_intensity(ambient_lightning);
	*max_sum = intensity_max(ambient_lightning->ratio, \
	*ambient_lightning->color);
}

//p: ray point at intersection
//v: object to camera
//s: specular
t_vector	light_intensity(t_vector normal, t_list *scene, \
t_vector p, t_vector v)
{
	t_obj		*i;
	t_vector	max_sum;
	t_vector	intensity;
	t_vector	l;
	t_closest	closest;

	init_intensity(&intensity, &max_sum, scene);
	while (scene != NULL)
	{
		i = scene->content;
		if (!str_cmp(i->id, "L"))
		{
			l = vector_normalized(vector_sub(*i->light->coordinate, p));
			closest = closest_intersection((t_ray){p, l, 1}, scene);
			if (closest.object == NULL || closest.parameter > vector_norm(l))
				intensity = vector_sum(intensity, \
				light_point_intensity(i->light, normal, v, l));
			max_sum = vector_sum(max_sum, intensity_max(i->light->ratio, \
			*i->light->color));
		}
		scene = scene->next;
	}
	return ((t_vector){intensity.x / max_sum.x, \
	intensity.y / max_sum.y, intensity.z / max_sum.z});
}
