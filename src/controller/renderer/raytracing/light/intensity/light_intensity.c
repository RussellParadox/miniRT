/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 03:37:14 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/05 10:35:27 by gdornic          ###   ########.fr       */
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

//p: ray point at intersection
//v: object to camera
//s: specular
t_vector	light_intensity(t_vector normal, t_list *scene, t_vector p, t_vector v, float s)
{
	t_obj		*i;
	t_vector	max_sum;
	t_vector	intensity;
	t_vector	l;
	t_closest	closest;

	intensity = (t_vector){0, 0, 0};
	max_sum = (t_vector){0, 0, 0};
	while (scene != NULL)
	{
		i = scene->content;
		if (!str_cmp(i->id, "A"))
		{
			intensity = vector_sum(intensity, ambient_lightning_intensity(i->ambient_lightning));
			max_sum = vector_sum(max_sum, intensity_max(i->ambient_lightning->ratio, *i->ambient_lightning->color));
		}
		else if (!str_cmp(i->id, "L"))
		{
			l = vector_normalized(vector_sub(*i->light->coordinate, p));
			closest = closest_intersection((t_ray){p, l, 1}, scene);
			if (closest.object == NULL || closest.parameter > vector_norm(l))
				intensity = vector_sum(intensity, light_point_intensity(i->light, normal, v, l, s));
			max_sum = vector_sum(max_sum, intensity_max(i->light->ratio, *i->light->color));
		}
		//max_sum = vector_sum(max_sum, intensity_max(object_ratio(i), *object_color(i)));
		scene = scene->next;
	}
	intensity.x /= max_sum.x;
	intensity.y /= max_sum.y;
	intensity.z /= max_sum.z;
	return (intensity);
}