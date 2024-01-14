/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:47:07 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/14 16:44:58 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	cylinder->diameter = ascii_to_float(data[3]);
	cylinder->height = ascii_to_float(data[4]);
	cylinder->color = NULL;
	cylinder_init(cylinder, data);
	if (errno == ENOMEM)
		return (cylinder_free(cylinder));
	return (cylinder);
}