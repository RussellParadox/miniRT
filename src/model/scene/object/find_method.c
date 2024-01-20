/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:58:14 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/19 22:21:14 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_obj_type	*object_content(t_obj *object)
{
	if (!str_cmp(object->id, "A"))
		return ((t_obj_type *)object->ambient_lightning);
	else if (!str_cmp(object->id, "C"))
		return ((t_obj_type *)object->camera);
	else if (!str_cmp(object->id, "L"))
		return ((t_obj_type *)object->light);
	else if (!str_cmp(object->id, "sp"))
		return ((t_obj_type *)object->sphere);
	else if (!str_cmp(object->id, "pl"))
		return ((t_obj_type *)object->plane);
	else if (!str_cmp(object->id, "cy"))
		return ((t_obj_type *)object->cylinder);
	return (NULL);
}

t_obj_type	*object_find(char *id, t_list *scene)
{
	t_obj	*object;

	while (scene != NULL)
	{
		object = scene->content;
		if (!str_cmp(object->id, id))
			return (object_content(object));
		scene = scene->next;
	}
	return (NULL);
}