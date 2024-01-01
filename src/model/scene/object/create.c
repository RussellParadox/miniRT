/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:40:50 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/01 15:59:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*object_create(char **data)
{
	t_obj	*object;

	object = malloc(sizeof(t_obj));
	if (object == NULL)
		return (NULL);
	object->id = ft_strlcpy(object->id, data[0], ft_strlen(data[0]));
	if (!ft_strncmp(data[0], "A", -1))
		object->ambient_lightning = ambient_lightning_create(data);
	else if (!ft_strncmp(data[0], "C", -1))
		object->camera = camera_create(data);
	else if (!ft_strncmp(data[0], "L", -1))
		object->light = light_create(data);
	else if (!ft_strncmp(data[0], "sp", -1))
		object->sphere = sphere_create(data);
	else if (!ft_strncmp(data[0], "pl", -1))
		object->plane = plane_create(data);
	else if (!ft_strncmp(data[0], "cy", -1))
		object->cylinder = cylinder_create(data);
	return (object);
}