/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:52:42 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/20 05:19:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	sphere->diameter = ascii_to_float(data[2]);
	sphere->color = NULL;
	sphere->specular = -1;
	sphere->reflective = -1;
	if (data[4] != NULL)
		sphere->specular = ascii_to_float(data[4]);
	if (data[4] != NULL && data[5] != NULL)
		sphere->reflective = ascii_to_float(data[5]);
	sphere_init(sphere, data);
	if (errno == ENOMEM)
		return (sphere_free(sphere));
	return (sphere);
}