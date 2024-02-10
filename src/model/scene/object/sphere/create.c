/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:52:42 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/10 16:22:47 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sphere_map_init(t_sphere *sphere, char **data)
{
	sphere->base[0] = (t_vector){0, 0, -1};
	sphere->base[1] = (t_vector){0, 1, 0};
	sphere->base[2] = (t_vector){1, 0, 0};
	if (data[5] != NULL && data[6] != NULL)
	{
		sphere->texture_map = map_create(data[6]);
		if (data[7] != NULL)
		{
			if (data[7][ft_strlen(data[7]) - 1] == '\n')
				data[7][ft_strlen(data[7]) - 1] = '\0';
			sphere->normal_map = map_create(data[7]);
		}
	}
}

static void	sphere_init(t_sphere *sphere, char **data)
{
	char	**split;

	split = ft_split(data[1], ',');
	if (split == NULL)
		return ;
	sphere->coordinate = vector_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (sphere->coordinate == NULL)
		return ;
	split = ft_split(data[3], ',');
	if (split == NULL)
		return ;
	sphere->color = color_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (sphere->color == NULL)
		return ;
}

t_sphere	*sphere_create(char **data)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (NULL);
	sphere->coordinate = NULL;
	sphere->color = NULL;
	sphere->texture_map = NULL;
	sphere->normal_map = NULL;
	sphere->diameter = fabsf(ascii_to_float(data[2]));
	sphere->specular = -1;
	sphere->reflective = -1;
	sphere_init(sphere, data);
	if (data[4] != NULL)
	{
		sphere->specular = ascii_to_float(data[4]);
		if (data[5] != NULL)
			sphere->reflective = ascii_to_float(data[5]);
		sphere_map_init(sphere, data);
	}
	if (errno == ENOMEM)
		return (sphere_free(sphere));
	return (sphere);
}