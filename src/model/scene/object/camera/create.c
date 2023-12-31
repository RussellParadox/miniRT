/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:33:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/02 16:32:15 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	camera_init(t_camera *camera, char **data)
{
	char	**split;

	split = ft_split(data[1], ',');
	if (split == NULL)
		return ;
	camera->coordinate = vector_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (camera->coordinate == NULL)
		return ;
	split = ft_split(data[2], ',');
	if (split == NULL)
		return ;
	camera->orientation = vector_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (camera->orientation == NULL)
		return ;
}

t_camera	*camera_create(char **data)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	camera->coordinate = NULL;
	camera->orientation = NULL;
	camera->fov = ascii_to_float(data[3]);
	camera_init(camera, data);
	if (errno == ENOMEM)
		return (camera_free(camera));
	return (camera);
}