/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflective_method.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 05:23:59 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 05:25:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	object_reflective(t_obj *object)
{
	if (!str_cmp(object->id, "sp"))
		return (object->sphere->reflective);
	else if (!str_cmp(object->id, "pl"))
		return (object->plane->reflective);
	else if (!str_cmp(object->id, "cy"))
		return (object->cylinder->reflective);
	else
		return (-1);
}