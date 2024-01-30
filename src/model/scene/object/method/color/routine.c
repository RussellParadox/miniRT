/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:54:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/29 16:45:42 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	object_color(t_obj *object, t_vector p)
{
	static t_color	default_color = (t_color){.red = 0, .green = 0, .blue = 0};

	if (object == NULL)
		return (default_color);
	if (!str_cmp(object->id, "A"))
		return (*object->ambient_lightning->color);
	else if (!str_cmp(object->id, "L"))
		return (*object->light->color);
	else if (!str_cmp(object->id, "sp"))
		return (sphere_color(object->sphere, p));
	else if (!str_cmp(object->id, "pl"))
		return (plane_color(object->plane, p));
	else if (!str_cmp(object->id, "cy"))
		return (cylinder_color(object->cylinder, p));
	else
		return (default_color);
}