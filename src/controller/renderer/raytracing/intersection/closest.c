/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:20:23 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/12 11:35:21 by gdornic          ###   ########.fr       */
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
	closest_parameter = INFINITY;
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
