/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 03:37:14 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/18 18:47:35 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	intensity_sum_add(t_vector *sum, float ratio, t_color *color)
{
	sum->x += ratio * color->red / color->sum;
	sum->y += ratio * color->green / color->sum;
	sum->z += ratio * color->blue / color->sum;
}

static void	arg_init(void *arg[3], t_vector *intersection, t_list *scene, t_vector *normal)
{
	arg[0] = intersection;
	arg[1] = (t_camera *)object_find("C", scene);
	arg[2] = normal;
}

void	light_intensity_model(t_vector *intensity, t_obj *object, t_list *scene, t_vector *intersection)
{
	t_obj		*i;
	t_vector	intensity_sum;
	t_vector	normal;
	void		*arg[3];

	vector_init(&intensity_sum, 0, 0, 0);
	object_normal_init(&normal, object, intersection);
	arg_init(arg, intersection, scene, &normal);
	while (scene != NULL)
	{
		i = scene->content;
		if (!ft_strncmp(i->id, "A", -1))
		{
			ambient_lightning_model(intensity, i->ambient_lightning);
			intensity_sum_add(&intensity_sum, i->ambient_lightning->ratio, i->ambient_lightning->color);
		}
		else if (!ft_strncmp(i->id, "L", -1))
		{
			light_point_model(intensity, i->light, object_specular(object), arg);
			intensity_sum_add(&intensity_sum, i->light->ratio, i->light->color);
		}
		scene = scene->next;
	}
	intensity->x /= intensity_sum.x;
	intensity->y /= intensity_sum.y;
	intensity->z /= intensity_sum.z;
}