/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:37:15 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 11:27:06 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	plane_map_init(t_plane *plane, char **data)
{
	t_ray	    ray;
	float		t;

	ray.origin = vector_sum((t_vector){plane->normal->y, plane->normal->z, -plane->normal->x}, *plane->coordinate);
	ray.direction = *plane->normal;
	t = ray_plane_intersection(ray, plane);
	plane->base[2] = vector_normalized(vector_sub(ray_point(ray, t), *plane->coordinate));
	plane->base[1] = *plane->normal;
	plane->base[0] = vector_normalized(vector_cross_product(*plane->normal, plane->base[2]));
	if (data[5] != NULL && data[6] != NULL)
	{
		plane->texture_map = map_create(data[6]);
		if (data[7] != NULL)
		{
			if (data[7][ft_strlen(data[7]) - 1] == '\n')
				data[7][ft_strlen(data[7]) - 1] = '\0';
			plane->normal_map = map_create(data[7]);
		}
	}
}

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
	*plane->normal = vector_normalized(*plane->normal);
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
	plane->texture_map = NULL;
	plane->normal_map = NULL;
	plane->specular = -1;
	plane->reflective = -1;
	plane_init(plane, data);
	if (data[4] != NULL)
	{
		plane->specular = ascii_to_float(data[4]);
		if (data[5] != NULL)
			plane->reflective = ascii_to_float(data[5]);
		plane_map_init(plane, data);
	}
	if (errno == ENOMEM)
		return (plane_free(plane));
	return (plane);
}