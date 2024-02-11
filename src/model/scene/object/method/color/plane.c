/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:32:24 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 08:56:38 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	plane_color(t_plane *plane, t_vector p)
{
	t_map		*map;

	map = plane->texture_map;
	if (map == NULL)
		return (*plane->color);
	return (plane_mapping(plane, map, p));
}
