/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:31:34 by gdornic           #+#    #+#             */
/*   Updated: 2024/02/11 10:16:59 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	plane_mapping(t_plane *plane, t_map *map, t_vector p)
{
	t_vector	local;
	int			u;
	int			v;

	local = vector_sub(p, *plane->coordinate);
	u = 10 * vector_scalar_product(local, plane->base[0]) + 0.5;
	v = 10 * vector_scalar_product(local, plane->base[2]) + 0.5;
	u = u % map->width;
	v = v % map->height;
	if (u < 0)
		u = map->width + u;
	if (v < 0)
		v = map->height + v;
	return (map->color[u][v]);
}
