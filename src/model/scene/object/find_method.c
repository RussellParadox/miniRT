/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:58:14 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/12 20:21:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_obj_type	*object_content(t_obj *object)
{
	if (!ft_strncmp(object->id, "A", -1))
		return ((t_obj_type *)object->ambient_lightning);
	else if (!ft_strncmp(object->id, "C", -1))
		return ((t_obj_type *)object->camera);
	else if (!ft_strncmp(object->id, "L", -1))
		return ((t_obj_type *)object->light);
	else if (!ft_strncmp(object->id, "sp", -1))
		return ((t_obj_type *)object->sphere);
	else if (!ft_strncmp(object->id, "pl", -1))
		return ((t_obj_type *)object->plane);
	else if (!ft_strncmp(object->id, "cy", -1))
		return ((t_obj_type *)object->cylinder);
	return (NULL);
}

t_obj_type	*object_find(char *id, t_list *scene)
{
	t_obj	*object;

	while (scene != NULL)
	{
		object = scene->content;
		if (!ft_strncmp(object->id, id, -1))
			return (object_content(object));
		scene = scene->next;
	}
	return (NULL);
}