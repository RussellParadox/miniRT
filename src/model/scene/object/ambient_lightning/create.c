/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:51:41 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:07:25 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ambient_lightning_init(t_ambient_lightning *ambient_lightning, \
char **data)
{
	char	**split;

	split = ft_split(data[2], ',');
	if (split == NULL)
		return ;
	ambient_lightning->color = color_create(split[0], split[1], split[2]);
	array_free(split, 2);
	if (ambient_lightning->color == NULL)
		return ;
}

t_ambient_lightning	*ambient_lightning_create(char **data)
{
	t_ambient_lightning	*ambient_lightning;

	ambient_lightning = malloc(sizeof(t_ambient_lightning));
	if (ambient_lightning == NULL)
		return (NULL);
	ambient_lightning->ratio = ascii_to_float(data[1]);
	ambient_lightning->color = NULL;
	ambient_lightning_init(ambient_lightning, data);
	if (errno == ENOMEM)
		return (ambient_lightning_free(ambient_lightning));
	return (ambient_lightning);
}
