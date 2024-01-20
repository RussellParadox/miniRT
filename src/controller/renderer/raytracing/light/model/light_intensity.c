/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 03:37:14 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 06:42:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	intensity_sum_add(t_vector *sum, float ratio, t_color *color)
{
	if (ratio < 0)
		return ;
	sum->x += ratio * color->red / color->sum;
	sum->y += ratio * color->green / color->sum;
	sum->z += ratio * color->blue / color->sum;
}

static void	arg_init(void *arg[4], t_vector *intersection, t_list *scene, t_vector *normal)
{
	arg[0] = intersection;
	arg[1] = (t_camera *)object_find("C", scene);
	arg[2] = normal;
	arg[3] = scene;
}

t_vector	light_intensity_model(t_vector normal, t_obj *object, t_list *scene, t_vector *intersection)
{
	t_obj		*i;
	t_vector	intensity_sum;
	t_vector	intensity;
	void		*arg[4];

	intensity = (t_vector){0, 0, 0};
	vector_init(&intensity_sum, 0, 0, 0);
	arg_init(arg, intersection, scene, &normal);
	while (scene != NULL)
	{
		i = scene->content;
		if (!str_cmp(i->id, "A"))
			ambient_lightning_model(&intensity, i->ambient_lightning);
		else if (!str_cmp(i->id, "L"))
			light_point_model(&intensity, i->light, object_specular(object), arg);
		intensity_sum_add(&intensity_sum, object_ratio(i), object_color(i));
		scene = scene->next;
	}
	intensity.x /= intensity_sum.x;
	intensity.y /= intensity_sum.y;
	intensity.z /= intensity_sum.z;
	return (intensity);
}