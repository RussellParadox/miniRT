/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:54:09 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/03 08:59:51 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*object_free(t_obj *object)
{
	if (!ft_strncmp(data[0], "A", -1))
		ambient_lightning_free(object->ambient_lightning);
	else if (!ft_strncmp(data[0], "C", -1))
		camera_free(object->camera);
	else if (!ft_strncmp(data[0], "L", -1))
		light_free(object->light);
	else if (!ft_strncmp(data[0], "sp", -1))
		sphere_free(object->sphere);
	else if (!ft_strncmp(data[0], "pl", -1))
		plane_free(object->plane);
	else if (!ft_strncmp(data[0], "cy", -1))
		cylinder_free(object->cylinder);
	free(object);
	return (NULL);
}