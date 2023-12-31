/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:54:09 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/04 09:50:42 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	object_free(void *content)
{
	t_obj	*object;

	object = (t_obj *)content;
	if (!ft_strncmp(object->id, "A", -1))
		ambient_lightning_free(object->ambient_lightning);
	else if (!ft_strncmp(object->id, "C", -1))
		camera_free(object->camera);
	else if (!ft_strncmp(object->id, "L", -1))
		light_free(object->light);
	else if (!ft_strncmp(object->id, "sp", -1))
		sphere_free(object->sphere);
	else if (!ft_strncmp(object->id, "pl", -1))
		plane_free(object->plane);
	else if (!ft_strncmp(object->id, "cy", -1))
		cylinder_free(object->cylinder);
	free(object);
}