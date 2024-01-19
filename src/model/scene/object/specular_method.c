/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_method.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:44:27 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/18 18:45:43 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	object_specular(t_obj *object)
{
	if (!ft_strncmp(object->id, "sp", -1))
		return (object->sphere->specular);
	else if (!ft_strncmp(object->id, "pl", -1))
		return (object->plane->specular);
	else if (!ft_strncmp(object->id, "cy", -1))
		return (object->cylinder->specular);
	else
		return (-1);
}