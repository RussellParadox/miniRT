/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:17:43 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/16 04:30:10 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	object_normal_init(t_vector *normal, t_obj *object, t_vector *intersection)
{
	if (!ft_strncmp(object->id, "sp", -1))
		sphere_normal(normal, object->sphere, intersection);
	/*
	else if (!ft_strncmp(object->id, "pl", -1))
		plane_normal(normal, object->plane, intersection);
	else if (!ft_strncmp(object->id, "cy", -1))
		cylinder_normal(normal, object->cylinder, intersection);
*/
}