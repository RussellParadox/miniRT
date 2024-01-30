/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:32:24 by gdornic           #+#    #+#             */
/*   Updated: 2024/01/30 17:57:00 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	plane_color(t_plane *plane, t_vector p)
{
	t_map		*map;
	t_vector	local;
	int			u;
	int			v;

	map = plane->texture_map;
	if (map == NULL)
		return (*plane->color);
	local = vector_sub(p, *plane->coordinate);
	u = vector_scalar_product(local, map->u) + 0.5;
	v = vector_scalar_product(local, map->v) + 0.5;
	u = u % map->width / 2 + map->width / 2;
	v = v % map->height / 2 + map->height / 2;
	return (map->color[u][v]);
}