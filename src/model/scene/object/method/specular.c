/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:44:27 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/29 11:17:52 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	object_specular(t_obj *object)
{
	if (!str_cmp(object->id, "sp"))
		return (object->sphere->specular);
	else if (!str_cmp(object->id, "pl"))
		return (object->plane->specular);
	else if (!str_cmp(object->id, "cy"))
		return (object->cylinder->specular);
	else
		return (-1);
}