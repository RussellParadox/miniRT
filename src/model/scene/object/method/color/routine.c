/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:54:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:56:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	object_color(t_obj *object, t_vector p, t_vector n)
{
	static t_color	default_color = (t_color){.red = 0, .green = 0, .blue = 0};

	if (object == NULL)
		return (default_color);
	if (!str_cmp(object->id, "A"))
		return (*object->ambient_lightning->color);
	else if (!str_cmp(object->id, "L"))
		return (*object->light->color);
	else if (!str_cmp(object->id, "sp"))
		return (sphere_color(object->sphere, n));
	else if (!str_cmp(object->id, "pl"))
		return (plane_color(object->plane, p));
	else if (!str_cmp(object->id, "cy"))
		return (cylinder_color(object->cylinder, p, n));
	else
		return (default_color);
}
