/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:37:15 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/18 18:43:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	plane_init(t_plane *plane, char **data)
{
	char	**split;

	split = ft_split(data[1], ',');
	if (split == NULL)
		return ;
	plane->coordinate = vector_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (plane->coordinate == NULL)
		return ;
	split = ft_split(data[2], ',');
	if (split == NULL)
		return ;
	plane->normal = vector_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (plane->normal == NULL)
		return ;
	split = ft_split(data[3], ',');
	if (split == NULL)
		return ;
	plane->color = color_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (plane->color == NULL)
		return ;
}

t_plane	*plane_create(char **data)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		return (NULL);
	plane->coordinate = NULL;
	plane->normal = NULL;
	plane->color = NULL;
	plane->specular = -1;
	if (data[4] != NULL)
		plane->specular = ascii_to_float(data[4]);
	plane_init(plane, data);
	if (errno == ENOMEM)
		return (plane_free(plane));
	return (plane);
}