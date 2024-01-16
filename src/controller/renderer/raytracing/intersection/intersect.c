/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:55:17 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/14 19:54:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ray_intersect(t_ray *ray, t_obj *object)
{
	if (object == NULL)
		return (FLT_MAX);
	if (!ft_strncmp(object->id, "sp", -1))
		return (ray_sphere_intersection(ray, object->sphere));
	else if (!ft_strncmp(object->id, "pl", -1))
		return (ray_plane_intersection(ray, object->plane));
	else if (!ft_strncmp(object->id, "cy", -1))
		return (ray_cylinder_intersection(ray, object->cylinder));
	else
		return (FLT_MAX);
}