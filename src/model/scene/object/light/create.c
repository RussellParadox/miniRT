/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:16:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/02 16:28:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	light_init(t_light *light, char **data)
{
	char	**split;

	split = ft_split(data[1]);
	if (split == NULL)
		return ;
	light->coordinate = vector_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (light->coordinate == NULL)
		return ;
	split = ft_split(data[3]);
	if (split == NULL)
		return ;
	light->color = color_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (light->color == NULL)
		return ;
}

t_light	*light_create(char **data)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		return (NULL);
	light->coordinate = NULL;
	light->ratio = ascii_to_float(data[2]);
	light->color = NULL;
	light_init(light, data);
	if (errno == ENOMEM)
		return (light_free(light));
	return (light);
}