/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:55:17 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/12 11:36:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ray_intersect(t_ray ray, t_obj *object)
{
	if (object == NULL)
		return (INFINITY);
	if (!str_cmp(object->id, "sp"))
		return (ray_sphere_intersection(ray, object->sphere));
	else if (!str_cmp(object->id, "pl"))
		return (ray_plane_intersection(ray, object->plane));
	else if (!str_cmp(object->id, "cy"))
		return (ray_cylinder_intersection(ray, object->cylinder));
	else
		return (INFINITY);
}
