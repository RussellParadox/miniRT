/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_method.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:54:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/19 22:21:14 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	*object_color(t_obj *object)
{
	static t_color	default_color = (t_color){.red = 0, .green = 0, .blue = 0};

	if (object == NULL)
		return (&default_color);
	if (!str_cmp(object->id, "A"))
		return (object->ambient_lightning->color);
	else if (!str_cmp(object->id, "L"))
		return (object->light->color);
	else if (!str_cmp(object->id, "sp"))
		return (object->sphere->color);
	else if (!str_cmp(object->id, "pl"))
		return (object->plane->color);
	else if (!str_cmp(object->id, "cy"))
		return (object->cylinder->color);
	else
		return (&default_color);
}