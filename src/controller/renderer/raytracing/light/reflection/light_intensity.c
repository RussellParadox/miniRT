/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 03:37:14 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/16 04:54:37 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	intensity_sum_add(t_vector *sum, float ratio, t_color *color)
{
	sum->x += ratio * color->red / color->sum;
	sum->y += ratio * color->green / color->sum;
	sum->z += ratio * color->blue / color->sum;
}

void	light_intensity_reflection(t_vector *intensity, t_vector *normal, t_list *scene, t_vector *intersection)
{
	t_obj		*object;
	t_vector	intensity_sum;

	intensity_sum.x = 0;
	intensity_sum.y = 0;
	intensity_sum.z = 0;
	while (scene != NULL)
	{
		object = scene->content;
		if (!ft_strncmp(object->id, "A", -1))
		{
			ambient_lightning_reflection(intensity, object->ambient_lightning);
			intensity_sum_add(&intensity_sum, object->ambient_lightning->ratio, object->ambient_lightning->color);
		}
		else if (!ft_strncmp(object->id, "L", -1))
		{
			light_reflection(intensity, normal, object->light, intersection);
			intensity_sum_add(&intensity_sum, object->light->ratio, object->light->color);
		}
		scene = scene->next;
	}
	intensity->x /= intensity_sum.x;
	intensity->y /= intensity_sum.y;
	intensity->z /= intensity_sum.z;
}