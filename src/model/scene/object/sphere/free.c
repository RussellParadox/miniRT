/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:58:50 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/29 16:15:21 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*sphere_free(t_sphere *sphere)
{
	if (sphere->coordinate != NULL)
		vector_free(sphere->coordinate);
	if (sphere->color != NULL)
		color_free(sphere->color);
	if (sphere->texture_map != NULL)
		map_free(sphere->texture_map);
	free(sphere);
	return (NULL);
}