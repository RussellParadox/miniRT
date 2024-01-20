/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:54:09 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/19 22:21:14 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	object_free(void *content)
{
	t_obj	*object;

	object = (t_obj *)content;
	if (!str_cmp(object->id, "A"))
		ambient_lightning_free(object->ambient_lightning);
	else if (!str_cmp(object->id, "C"))
		camera_free(object->camera);
	else if (!str_cmp(object->id, "L"))
		light_free(object->light);
	else if (!str_cmp(object->id, "sp"))
		sphere_free(object->sphere);
	else if (!str_cmp(object->id, "pl"))
		plane_free(object->plane);
	else if (!str_cmp(object->id, "cy"))
		cylinder_free(object->cylinder);
	free(object);
}