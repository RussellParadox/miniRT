/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:47:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/01 18:15:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cylinder_map_init(t_cylinder *cylinder, char **data)
{
	t_plane		plane;
	t_ray	    ray;
	float		t;

	ray.origin = vector_sum((t_vector){cylinder->axis->y, -cylinder->axis->z, cylinder->axis->x}, *cylinder->coordinate);
	ray.direction = *cylinder->axis;
	plane.coordinate = cylinder->coordinate;
	plane.normal = cylinder->axis;
	t = ray_plane_intersection(ray, &plane);
	cylinder->base[2] = vector_normalized(vector_sub(ray_point(ray, t), *cylinder->coordinate));
	cylinder->base[1] = *cylinder->axis;
	cylinder->base[0] = vector_normalized(vector_cross_product(cylinder->base[1], cylinder->base[2]));
	if (data[7] != NULL && data[8] != NULL)
	{
		if (data[8][ft_strlen(data[8]) - 1] == '\n')
			data[8][ft_strlen(data[8]) - 1] = '\0';
		cylinder->texture_map = map_create(data[8]);
	}
}

static void	cylinder_init(t_cylinder *cylinder, char **data)
{
	char	**split;

	split = ft_split(data[1], ',');
	if (split == NULL)
		return ;
	cylinder->coordinate = vector_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (cylinder->coordinate == NULL)
		return ;
	split = ft_split(data[2], ',');
	if (split == NULL)
		return ;
	cylinder->axis = vector_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (cylinder->axis == NULL)
		return ;
	*cylinder->axis = vector_normalized(*cylinder->axis);
	split = ft_split(data[5], ',');
	if (split == NULL)
		return ;
	cylinder->color = color_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (cylinder->color == NULL)
		return ;
}

t_cylinder	*cylinder_create(char **data)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (NULL);
	cylinder->coordinate = NULL;
	cylinder->axis = NULL;
	cylinder->color = NULL;
	cylinder->texture_map = NULL;
	cylinder->diameter = ascii_to_float(data[3]);
	cylinder->height = ascii_to_float(data[4]);
	cylinder->specular = -1;
	cylinder->reflective = -1;
	cylinder_init(cylinder, data);
	if (data[6] != NULL)
	{
		cylinder->specular = ascii_to_float(data[6]);
		if (data[7] != NULL)
			cylinder->reflective = ascii_to_float(data[7]);
		cylinder_map_init(cylinder, data);
	}
	if (errno == ENOMEM)
		return (cylinder_free(cylinder));
	return (cylinder);
}