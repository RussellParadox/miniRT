/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:40:50 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:54:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*object_create(char **data)
{
	t_obj	*object;

	object = malloc(sizeof(t_obj));
	if (object == NULL)
		return (NULL);
	ft_strlcpy(object->id, data[0], ft_strlen(data[0]) + 1);
	if (!str_cmp(data[0], "A"))
		object->ambient_lightning = ambient_lightning_create(data);
	else if (!str_cmp(data[0], "C"))
		object->camera = camera_create(data);
	else if (!str_cmp(data[0], "L"))
		object->light = light_create(data);
	else if (!str_cmp(data[0], "sp"))
		object->sphere = sphere_create(data);
	else if (!str_cmp(data[0], "pl"))
		object->plane = plane_create(data);
	else if (!str_cmp(data[0], "cy"))
		object->cylinder = cylinder_create(data);
	return (object);
}
