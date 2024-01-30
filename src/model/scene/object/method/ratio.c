/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:03:23 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/29 11:17:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	object_ratio(t_obj *object)
{
	if (!str_cmp(object->id, "A"))
		return (object->ambient_lightning->ratio);
	else if (!str_cmp(object->id, "L"))
		return (object->light->ratio);
	else
		return (-1);
}