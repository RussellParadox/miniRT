/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:02:48 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:56:27 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	bump_normal(t_obj *object, t_vector p, t_vector n)
{
	if (!str_cmp(object->id, "sp"))
		return (sphere_bump(object->sphere, n));
	else if (!str_cmp(object->id, "pl"))
		return (plane_bump(object->plane, p));
	else if (!str_cmp(object->id, "cy"))
		return (cylinder_bump(object->cylinder, p, n));
	else
		return ((t_vector){0, 0, 0});
}
