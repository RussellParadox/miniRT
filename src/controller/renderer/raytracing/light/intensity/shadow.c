/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:37:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/05 08:39:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	shadow_model(t_list *scene, t_vector *intersection, t_vector *l)
{
	float		parameter;
	float		parameter_min;
	t_obj		*object;
	t_obj		*closest_object;
	t_ray		ray;

	ray.origin = intersection;
	ray.direction = l;
	closest_object = NULL;
	parameter_min = FLT_MAX;
	while (scene != NULL)
	{
		object = scene->content;
		parameter = ray_intersect(&ray, object);
		if (parameter < parameter_min && parameter > PRECISION)
		{
			parameter_min = parameter;
			closest_object = object;
		}
		scene = scene->next;
	}
	if (closest_object == NULL)
		return (0);
	return (1);
}