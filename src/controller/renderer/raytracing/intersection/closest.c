/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:20:23 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/25 16:22:51 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_closest	closest_intersection(t_ray ray, t_list *scene)
{
	float		parameter;
	float		closest_parameter;
	t_obj		*object;
	t_obj		*closest_object;

	closest_object = NULL;
	closest_parameter = FLT_MAX;
	while (scene != NULL)
	{
		object = scene->content;
		parameter = ray_intersect(ray, object);
		if (parameter < closest_parameter && parameter > ray.parameter_min)
		{
			closest_parameter = parameter;
			closest_object = object;
		}
		scene = scene->next;
	}
	return ((t_closest){closest_object, closest_parameter});
}
