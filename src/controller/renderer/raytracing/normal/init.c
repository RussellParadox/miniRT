/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:17:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/19 22:21:14 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	object_normal_init(t_vector *normal, t_obj *object, t_vector *intersection)
{
	if (!str_cmp(object->id, "sp"))
		sphere_normal(normal, object->sphere, intersection);
	else if (!str_cmp(object->id, "pl"))
		plane_normal(normal, object->plane);
	else if (!str_cmp(object->id, "cy"))
		cylinder_normal(normal, object->cylinder, intersection);
}