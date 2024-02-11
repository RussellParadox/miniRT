/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:34:20 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:56:02 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*light_free(t_light *light)
{
	if (light->coordinate != NULL)
		vector_free(light->coordinate);
	if (light->color != NULL)
		color_free(light->color);
	free(light);
	return (NULL);
}
