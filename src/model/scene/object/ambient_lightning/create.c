/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:51:41 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/01 22:58:52 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ambient_lightning	*ambient_lightning_create(char **data)
{
	t_ambient_lightning	*ambient_lightning;
	char				**color_data;

	ambient_lightning = malloc(sizeof(ambient_lightning));
	if (ambient_lightning == NULL)
		return (NULL);
	ambient_lightning->ratio = ascii_to_float(data[1]);
	ambient_lightning->color = NULL;
	color_data = ft_split(data[2], ',');
	if (color_data == NULL)
		return (ambient_lightning_free(ambient_lightning));
	ambient_lightning->color = color_create(color_data[0], color_data[1], color_data[2]);
	if (ambient_lightning->color == NULL)
		return (ambient_lightning_free(ambient_lightning));
	return (ambient_lightning);
}