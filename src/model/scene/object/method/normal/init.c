/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:17:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/27 18:04:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	object_normal(t_obj *object, t_vector intersection, t_vector d)
{
	t_vector	normal;

	if (!str_cmp(object->id, "sp"))
		normal = sphere_normal(object->sphere, intersection);
	else if (!str_cmp(object->id, "pl"))
		normal = plane_normal(object->plane, d);
	else if (!str_cmp(object->id, "cy"))
		normal = cylinder_normal(object->cylinder, intersection);
	return (normal);
}