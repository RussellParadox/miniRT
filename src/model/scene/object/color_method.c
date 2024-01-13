/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_method.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:54:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/12 20:22:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	*object_color(t_obj *object)
{
	static t_color	default_color = (t_color){.red = 0, .green = 0, .blue = 0};

	if (object == NULL)
		return (&default_color);
	if (!ft_strncmp(object->id, "A", -1))
		return (object->ambient_lightning->color);
	else if (!ft_strncmp(object->id, "L", -1))
		return (object->light->color);
	else if (!ft_strncmp(object->id, "sp", -1))
		return (object->sphere->color);
	else if (!ft_strncmp(object->id, "pl", -1))
		return (object->plane->color);
	else if (!ft_strncmp(object->id, "cy", -1))
		return (object->cylinder->color);
	else
		return (&default_color);
}